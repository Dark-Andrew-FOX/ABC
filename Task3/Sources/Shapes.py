import random
from Sphere import Sphere
from Parallelepiped import Parallelepiped
from RightTetrahedron import RightTetrahedron


class Shapes:
    length = None
    items = []

    # Конструктор.
    def __init__(self):
        self.length = 0

    # Деструктор.
    def __del__(self):
        self.clear()

    def clear(self):
        # del self.items
        print()

    # Ввод содержимого контейнера из указанного потока.
    def input(self, file):
        line = file.readline()

        while line:
            kind = line[0]
            data = file.readline().split(' ')
            density = data[0]

            if kind == '1':
                # Сфера.
                radius = data[1].replace("\n", "")
                sphere = Sphere(density, radius)
                self.items.append(sphere)
            else:
                if kind == '2':
                    # Параллелепипед.
                    a = data[1]
                    b = data[2]
                    c = data[3]
                    self.items.append(Parallelepiped(density, a, b, c))
                else:
                    if kind == '3':
                        # Правильный тетраэдр.
                        a = data[1]
                        self.items.append(RightTetrahedron(density, a))

            line = file.readline()
            self.length = self.length + 1

    # Случайный ввод содержимого контейнера.
    def input_random(self, size):
        while self.length < size:
            # Сгенерируем тип фигуры.
            kind = random.randint(1, 3)

            if kind == 1:
                # Сфера.
                self.items.append(Sphere())
            else:
                if kind == 2:
                    # Параллелепипед.
                    self.items.append(Parallelepiped())
                else:
                    if kind == 3:
                        # Правильный тетраэдр.
                        self.items.append(RightTetrahedron())
            self.length = self.length + 1

    def output(self, file):
        print("Container contains ", len(self.items), "elements.", file=file)

        counter = 1
        for i in self.items:
            print(counter, ")", i.output(), file=file)
            counter = counter + 1

    # Сортировка контейнера.
    def quicksort(self, first, last):
        f = first
        l = last
        mid = self.items[(f + l) // 2]  # вычисление опорного элемента

        condition = True
        while condition:
            while self.items[f].get_area() > mid.get_area():
                f = f + 1
            while self.items[l].get_area() < mid.get_area():
                l = l - 1

            if f <= l:
                temp = self.items[f]
                self.items[f] = self.items[l]
                self.items[l] = temp
                f = f + 1
                l = l - 1

            condition = f < l
        # Эмуляция do while

        if first < l:
            self.quicksort(first, l)
        if f < last:
            self.quicksort(f, last)
