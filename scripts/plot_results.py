import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DATA_DIR = ROOT / "data"
FIGURES_DIR = ROOT / "figures"

FIGURES_DIR.mkdir(exist_ok=True)

standard_data = pd.read_csv(DATA_DIR / "experiment_results.csv")
comparison_data = pd.read_csv(DATA_DIR / "comparison_results.csv")

plt.figure()
plt.plot(standard_data["Samples"], standard_data["MeanError"], marker="o")
plt.xscale("log")
plt.yscale("log")
plt.xlabel("Number of Samples")
plt.ylabel("Mean Absolute Error")
plt.title("Mean Absolute Error as a Function of Sample Size")
plt.grid(True, which="both", linestyle="--", linewidth=0.5, alpha=0.5)
plt.savefig(FIGURES_DIR / "error_vs_samples.png", dpi=300, bbox_inches="tight")
plt.close()

plt.figure()
plt.plot(standard_data["Samples"], standard_data["Runtime"], marker="o")
plt.xscale("log")
plt.yscale("log")
plt.xlabel("Number of Samples")
plt.ylabel("Runtime (ms)")
plt.title("Runtime Scaling of Monte Carlo Simulation")
plt.grid(True, which="both", linestyle="--", linewidth=0.5, alpha=0.5)
plt.savefig(FIGURES_DIR / "runtime_vs_samples.png", dpi=300, bbox_inches="tight")
plt.close()

plt.figure()
plt.plot(standard_data["Samples"], standard_data["StdDev"], marker="o")
plt.xscale("log")
plt.yscale("log")
plt.xlabel("Number of Samples")
plt.ylabel("Standard Deviation")
plt.title("Estimator Standard Deviation vs. Sample Size")
plt.grid(True, which="both", linestyle="--", linewidth=0.5, alpha=0.5)
plt.savefig(FIGURES_DIR / "stddev_vs_samples.png", dpi=300, bbox_inches="tight")
plt.close()

plt.figure()
plt.plot(standard_data["Samples"], standard_data["CI95"], marker="o")
plt.xscale("log")
plt.yscale("log")
plt.xlabel("Number of Samples")
plt.ylabel("95% Confidence Interval Width")
plt.title("95% Confidence Interval Width vs. Sample Size")
plt.grid(True, which="both", linestyle="--", linewidth=0.5, alpha=0.5)
plt.savefig(FIGURES_DIR / "ci95_vs_samples.png", dpi=300, bbox_inches="tight")
plt.close()

plt.figure()
plt.plot(
    comparison_data["Samples"],
    comparison_data["StandardMCMeanError"],
    marker="o",
    label="Standard Monte Carlo"
)
plt.plot(
    comparison_data["Samples"],
    comparison_data["StratifiedMCMeanError"],
    marker="o",
    label="Stratified Monte Carlo"
)
plt.xscale("log")
plt.yscale("log")
plt.xlabel("Number of Samples")
plt.ylabel("Mean Absolute Error")
plt.title("Mean Absolute Error: Standard vs. Stratified Monte Carlo")
plt.grid(True, which="both", linestyle="--", linewidth=0.5, alpha=0.5)
plt.legend()
plt.savefig(FIGURES_DIR / "comparison_error.png", dpi=300, bbox_inches="tight")
plt.close()

print("All figures generated successfully.")
