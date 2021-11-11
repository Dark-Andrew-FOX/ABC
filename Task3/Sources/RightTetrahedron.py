import math
from Shape import Shape
from Random20 import random20


class RightTetrahedron(Shape):
    length_of_edge = None

    # Конструктор.
    def __init__(self, density=-1, length_of_edge=-1):
        if density == -1:
            super().__init__(random20())
            self.length_of_edge = random20()
        else:
            super().__init__(density)
            self.length_of_edge = int(length_of_edge)

    def get_area(self):
        return math.sqrt(3) * (self.length_of_edge ** 2)

    def output(self):
        return "This is RightTetrahedron: length_of_edge = {0}; density: {1}; Area = {2}" \
            .format(self.length_of_edge, self.density, self.get_area())
