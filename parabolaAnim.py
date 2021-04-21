import numpy as np
from matplotlib import pyplot as plt
from matplotlib import animation

fig = plt.figure()

ax = plt.axes(xlim = (-5, 10), ylim = (-5,10))
line, = ax.plot([], [], lw=2)

def init():
    line.set_data([],[])
    return line,

def animate(i):
    x = np.linspace(0,2, 500)
    y = 0.01 * i * (x - 1) * (x - 2)#parabola
    #y = 0.01 * i * pow(x, 2)#exponencial
    # y = 0.01 * i * pow(x, 4) - pow(x, 2)
    # (x - 6)² + y(y - 6)² = 4
    line.set_data(x, y)
    return line,

anim = animation.FuncAnimation(fig, animate, init_func=init, frames=200, interval=20, blit=True)

plt.show()