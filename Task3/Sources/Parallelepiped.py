from Shape import Shape
from Random20 import random20


class Parallelepiped(Shape):
    first_edge = None
    second_edge = None
    third_edge = None

    # Конструктор.
    def __init__(self, density=-1, first_edge=-1, second_edge=-1, third_edge=-1):
        if density == -1:
            super().__init__(random20())
            self.first_edge = random20()
            self.second_edge = random20()
            self.third_edge = random20()
        else:
            super().__init__(density)
            self.first_edge = int(first_edge)
            self.second_edge = int(second_edge)
            self.third_edge = int(third_edge)

    def get_area(self):
        return 2 * (self.first_edge * self.second_edge
                    + self.second_edge * self.third_edge
                    + self.first_edge * self.third_edge)

    def output(self):
        return "This is Parallelepiped: " \
               "first_edge = {0}; second_edge = {1}; third_edge = {2}; density: {3}; Area = {4}" \
            .format(self.first_edge, self.second_edge, self.third_edge, self.density, self.get_area())
