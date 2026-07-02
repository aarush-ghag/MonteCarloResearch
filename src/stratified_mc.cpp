#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>

using namespace std;

const long double TRUE_PI = acosl(-1.0L);

long double estimatePiStratified(int gridSize) {
    mt19937 rng(42);
    uniform_real_distribution<long double> dist(0.0L, 1.0L);

    int inside = 0;
    int totalSamples = gridSize * gridSize;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            long double x = (i + dist(rng)) / gridSize;
            long double y = (j + dist(rng)) / gridSize;

            if (x * x + y * y <= 1.0L) {
                inside++;
            }
        }
    }

    return 4.0L * inside / totalSamples;
}

int main() {
    cout << fixed << setprecision(10);

    int gridSizes[] = {
        32,
        100,
        316,
        1000
    };

    cout << "-------------------------------------------------------------\n";
    cout << "| Grid Size | Samples | Pi Estimate | Absolute Error |\n";
    cout << "-------------------------------------------------------------\n";

    for (int grid : gridSizes) {
        int samples = grid * grid;
        long double piEstimate = estimatePiStratified(grid);

        cout << "| "
             << setw(9) << grid << " | "
             << setw(8) << samples << " | "
             << setw(11) << piEstimate << " | "
             << setw(14) << fabsl(piEstimate - TRUE_PI) << " |\n";
    }

    cout << "-------------------------------------------------------------\n";

    return 0;
}