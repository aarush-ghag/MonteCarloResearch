#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <cmath>
#include <vector>

using namespace std;

const long double TRUE_PI = acosl(-1.0L);

long double estimatePi(unsigned long long samples) {
    mt19937 randomEngine(42);
    uniform_real_distribution<long double> distribution(0.0L, 1.0L);

    unsigned long long insideCircle = 0;

    for (unsigned long long i = 0; i < samples; i++) {
        long double x = distribution(randomEngine);
        long double y = distribution(randomEngine);

        if (x * x + y * y <= 1.0L) {
            insideCircle++;
        }
    }

    return 4.0L * static_cast<long double>(insideCircle) / samples;
}

int main() {
    vector<unsigned long long> sampleSizes = {
        1000,
        10000,
        100000,
        1000000,
        10000000
    };

    cout << fixed << setprecision(10);
    cout << "-------------------------------------------------------------\n";
    cout << "| Samples     | Pi Estimate  | Absolute Error | Runtime ms |\n";
    cout << "-------------------------------------------------------------\n";

    for (unsigned long long samples : sampleSizes) {
        auto start = chrono::high_resolution_clock::now();

        long double piEstimate = estimatePi(samples);

        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> runtime = end - start;
        long double error = fabsl(piEstimate - TRUE_PI);

        cout << "| "
             << setw(11) << samples << " | "
             << setw(12) << piEstimate << " | "
             << setw(14) << error << " | "
             << setw(10) << runtime.count() << " |\n";
    }

    cout << "-------------------------------------------------------------\n";

    return 0;
}