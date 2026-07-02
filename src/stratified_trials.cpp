#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <cmath>
#include <vector>

using namespace std;

const long double TRUE_PI = acosl(-1.0L);
const int TRIALS = 100;

long double estimatePiStratified(int gridSize, unsigned int seed) {
    mt19937 rng(seed);
    uniform_real_distribution<long double> dist(0.0L, 1.0L);

    unsigned long long inside = 0;
    unsigned long long totalSamples =
        static_cast<unsigned long long>(gridSize) * gridSize;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            long double x = (i + dist(rng)) / gridSize;
            long double y = (j + dist(rng)) / gridSize;

            if (x * x + y * y <= 1.0L) {
                inside++;
            }
        }
    }

    return 4.0L * static_cast<long double>(inside) / totalSamples;
}

long double mean(const vector<long double>& values) {
    long double sum = 0.0L;

    for (long double value : values) {
        sum += value;
    }

    return sum / values.size();
}

long double standardDeviation(const vector<long double>& values, long double avg) {
    long double sumSquaredDifferences = 0.0L;

    for (long double value : values) {
        long double difference = value - avg;
        sumSquaredDifferences += difference * difference;
    }

    return sqrtl(sumSquaredDifferences / (values.size() - 1));
}

int main() {
    vector<int> gridSizes = {
        32,
        100,
        316,
        1000
    };

    cout << fixed << setprecision(10);
    cout << "--------------------------------------------------------------------------------------------------\n";
    cout << "| Grid Size | Samples    | Mean Pi      | Mean Abs Error | Std Dev      | 95% CI +/-   | Runtime ms |\n";
    cout << "--------------------------------------------------------------------------------------------------\n";

    for (int grid : gridSizes) {
        vector<long double> estimates;
        vector<long double> errors;

        unsigned long long samples =
            static_cast<unsigned long long>(grid) * grid;

        auto start = chrono::high_resolution_clock::now();

        for (int trial = 0; trial < TRIALS; trial++) {
            long double piEstimate = estimatePiStratified(grid, 42 + trial);
            estimates.push_back(piEstimate);
            errors.push_back(fabsl(piEstimate - TRUE_PI));
        }

        auto end = chrono::high_resolution_clock::now();

        long double meanPi = mean(estimates);
        long double meanError = mean(errors);
        long double stdDev = standardDeviation(estimates, meanPi);
        long double ci95 = 1.96L * stdDev / sqrtl(TRIALS);

        chrono::duration<double, milli> runtime = end - start;

        cout << "| "
             << setw(9) << grid << " | "
             << setw(10) << samples << " | "
             << setw(12) << meanPi << " | "
             << setw(14) << meanError << " | "
             << setw(12) << stdDev << " | "
             << setw(12) << ci95 << " | "
             << setw(10) << runtime.count() << " |\n";
    }

    cout << "--------------------------------------------------------------------------------------------------\n";

    return 0;
}