#ifndef ABC2_SHAPES_H
#define ABC2_SHAPES_H

#include "Shape.h"

#include "Sphere.h"
#include "Parallelepiped.h"
#include "RightTetrahedron.h"

using namespace std;

class Shapes {
public:
    // Конструктор контейнера.
    Shapes() {
        lenght = 0;
    }

    // Деструктор контейнера.
    ~Shapes() {
        Clear();
    }

    // Ввод содержимого контейнера из указанного потока
    void Input(ifstream& ifst);

    // Случайный ввод содержимого контейнера
    void InputRandom(int size);

    // Вывод содержимого контейнера в указанный поток
    void Output(ofstream& ofst);

    // Возвращение длины контейнера.
    int GetLength() {
        return lenght;
    }

    // Сортировка контейнера.
    void Quicksort(int first, int last);

    // Очистка контейнера от элементов (освобождение памяти).
    void Clear();

private:
    // Текущая длина.
    int lenght;

    Shape* items[10000];
};


#endif //ABC2_SHAPES_H
