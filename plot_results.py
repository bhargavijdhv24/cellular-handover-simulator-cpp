import matplotlib.pyplot as plt
import os

x_vals = []
y_vals = []

# Read simulation results
with open("data/handover_log.txt", "r") as f:
    for line in f:
        x, y, bs = line.strip().split(",")
        x_vals.append(int(x))
        y_vals.append(int(bs.replace("BS", "")))

# Create docs folder if not exists
os.makedirs("docs", exist_ok=True)

# Plot
plt.figure(figsize=(8,4))
plt.plot(x_vals, y_vals, marker='o', linestyle='-')
plt.title("Handover Events Across Base Stations")
plt.xlabel("Device Position (x)")
plt.ylabel("Connected Base Station")
plt.grid(True)

# Save graph
output_path = "docs/handover_graph.png"
plt.savefig(output_path, dpi=300)
print(f"Graph saved to {output_path}")

# Show graph (optional)
plt.show()
