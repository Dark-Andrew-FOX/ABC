import math
from Shape import Shape
from Random20 import random20


class Sphere(Shape):
    radius = None

    # Конструктор.
    def __init__(self, density=-1, radius=-1):
        if density == -1:
            super().__init__(random20())
            self.radius = random20()
        else:
            super().__init__(density)
            self.radius = int(radius)

    def get_area(self):
        return 4 * math.pi * self.radius ** 2

    def output(self):
        return "This is Sphere: radius = {0}; density: {1}; Area = {2}" \
            .format(self.radius, self.density, self.get_area())
