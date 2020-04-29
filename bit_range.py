import matplotlib.pyplot as plt
import numpy as np

T = 20
n = np.arange(21)
x = np.sin(2.0 * np.pi / T * n)

fig = plt.figure(figsize=(13, 5))

ax1 = fig.add_subplot(1, 2, 1)
ax2 = ax1.twinx()

ax1.stem(n, x)
ax1.set_title("8bit")
ax1.set_xlabel("Time[sample]")
ax1.set_ylabel("Amplitude")
ax1.set_xticks(n)
ax1.hlines(y=[-1, 1], xmin=0, xmax=20, linestyles='dashed', linewidths=0.5)
ax1.set_ylim(-1.2, 1.2)
ax1.set_yticks([-1, 0, 1])
ax2.set_ylim([-1.2, 1.2])
ax2.set_yticks([-1, 0, 1])
ax2.set_yticklabels([0, 128, 255])

ax3 = fig.add_subplot(1, 2, 2)
ax4 = ax3.twinx()

ax3.stem(n, x)
ax3.set_title("16bit")
ax3.set_xlabel("Time[sample]")
ax3.set_xticks(n)
ax3.hlines(y=[-1, 1], xmin=0, xmax=20, linestyles='dashed', linewidths=0.5)
ax3.set_ylim(-1.2, 1.2)
ax3.set_yticks([-1, 0, 1])
ax4.set_ylim([-1.2, 1.2])
ax4.set_yticks([-1, 0, 1])
ax4.set_yticklabels([-32768, 0, 32767])

plt.show()
