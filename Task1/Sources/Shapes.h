#ifndef __Shapes__
#define __Shapes__

#include "Shape.h"

// Максимальная длина контейнера.
const int MAX_ITEMS = 10000;

// Контейнер на основе одномерного массива.
struct Shapes {
    // Текущая длина.
    int len;
    Shape *items[MAX_ITEMS];
};

// Инициализация контейнера.
void Init(Shapes &shapes);

// Очистка контейнера от элементов (освобождение памяти).
void Clear(Shapes &shapes);

// Ввод содержимого контейнера из указанного потока.
void In(Shapes &shapes, ifstream &inputStream);

// Случайный ввод содержимого контейнера.
void InRnd(Shapes &shapes, int size);

// Вывод содержимого контейнера в указанный поток.
void Out(Shapes &shapes, ofstream &outputStream);

// Сортировка контейнера.
void Quicksort(Shapes& shapes, int first, int last);

#endif
