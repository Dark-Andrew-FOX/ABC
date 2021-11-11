from Random20 import random20


class Shape:
    # Общий признак - плотность фигуры.
    density = None

    # Базовый конструктор.
    def __init__(self, density):
        self.density = density
