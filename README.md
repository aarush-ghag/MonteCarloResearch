# Empirical Evaluation of Monte Carlo Sampling Strategies for Numerical Integration

An undergraduate research project investigating the performance of Monte Carlo sampling strategies for numerical integration through reproducible C++ implementations, statistical analysis, and algorithmic comparison.

![Comparison of Standard and Stratified Monte Carlo](figures/comparison_error.png)

---

## Overview

Monte Carlo methods are widely used in scientific computing, machine learning, computational physics, quantitative finance, and Bayesian inference to approximate numerical quantities through random sampling.

This project evaluates the performance of **Standard Monte Carlo** and **Stratified Monte Carlo** sampling strategies using the numerical estimation of π as a reproducible benchmark problem. Rather than treating π estimation as the primary objective, the project investigates how different sampling strategies influence estimator accuracy, convergence behavior, statistical reliability, and computational performance.

The project extends a traditional classroom implementation into a structured empirical study through automated benchmarking, repeated statistical experimentation, reproducible random number generation, and comparative algorithm evaluation.

---

## Research Objectives

This project investigates the following questions:

- How does estimation accuracy change as the number of Monte Carlo samples increases?
- How does Stratified Monte Carlo compare with Standard Monte Carlo under identical computational budgets?
- What trade-offs exist between estimation accuracy and computational performance?
- How do repeated statistical trials improve the reliability of experimental conclusions?

---

## Methodology

The experimental framework includes:

- Standard Monte Carlo implementation in C++
- Stratified Monte Carlo implementation
- `std::mt19937` Mersenne Twister random number generator
- Automated benchmarking across multiple sample sizes
- 100 independent trials per experiment
- Runtime measurement using the C++ `<chrono>` library
- Statistical analysis including:
  - Mean estimated value of π
  - Mean absolute error
  - Standard deviation
  - 95% confidence interval

---

## Key Findings

The experimental evaluation demonstrated that:

- Both algorithms converge toward the true value of π as sample size increases.
- Stratified Monte Carlo consistently achieved lower mean absolute error than Standard Monte Carlo.
- Variance reduction significantly improved estimator stability without requiring a proportional increase in computational cost.
- Repeated statistical experimentation provides a more reliable assessment than single-run evaluations.

---

## Repository Structure

```text
paper/
    Empirical_Evaluation_of_Monte_Carlo_Sampling_Strategies.pdf

src/
    standard_mc.cpp
    stratified_mc.cpp
    stratified_trials.cpp

scripts/
    plot_results.py

figures/
    comparison_error.png
    error_vs_samples.png
    runtime_vs_samples.png
    stddev_vs_samples.png
    ci95_vs_samples.png

data/
    experiment_results.csv
    stratified_results.csv
```

---

## Technologies

- C++20
- Python
- Matplotlib
- GNU g++
- Git
- GitHub

---

## Building the Project

Compile using:

```bash
g++ -std=c++20 -O2 standard_mc.cpp -o standard_mc
```

Run:

```bash
./standard_mc
```

Similar commands may be used for the additional implementations included in the repository.

---

## Future Work

Potential extensions include:

- Importance Sampling
- Latin Hypercube Sampling
- Quasi-Monte Carlo methods
- OpenMP parallelization
- GPU acceleration
- Higher-dimensional numerical integration
- Additional benchmark functions

---

## Author

**Aarush Ghag**

Computer Science Undergraduate  
California State University, Chico

---

## License

This project is released under the MIT License.
