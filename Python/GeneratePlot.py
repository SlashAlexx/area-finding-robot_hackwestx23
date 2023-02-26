import time
import app
import numpy as np
from matplotlib import pyplot as plt

coordinate_list = np.array([0,0])
current_position = []
previous_coordinate = []

# Starting Variables
velocity = 5
current_position = [0, 0]
previous_coordinate = [0, 0]


#Plots New Corner
def NewCorner(direction, deltaTime):
    global current_position
    displacement = deltaTime * velocity
    current_position += np.dot(direction, displacement)
    plt.scatter(current_position[0], current_position[1], c = 'Blue')

NewCorner([0, 1], 10)
NewCorner([-1, 0], 15)
NewCorner([0, -1], 50)
NewCorner([1, 0], 30)
NewCorner([0, 1], 25)
NewCorner([-1, 0], 10)

plt.show()