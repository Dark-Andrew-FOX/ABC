#include "Shapes.h"

// Инициализация контейнера.
void Init(Shapes & shapes) {
    shapes.len = 0;
}

// Очистка контейнера от элементов (освобождение памяти).
void Clear(Shapes &shapes) {
    for(int i = 0; i < shapes.len; i++) {
        delete shapes.items[i];
    }
    shapes.len = 0;
}

// Ввод содержимого контейнера из указанного потока.
void In(Shapes &shapes, ifstream &inputStream) {
    while(!inputStream.eof()) {
        if((shapes.items[shapes.len] = In(inputStream)) != 0) {
            shapes.len++;
        }
    }
}

// Случайный ввод содержимого контейнера.
void InRnd(Shapes &shapes, int size) {
    // Генерируем, пока не сгенерируем нужное кол-во.
    while(shapes.len < size) {
        // Если генерация прошла успешно, увеличиваем len.
        if((shapes.items[shapes.len] = InRnd()) != nullptr) {
            ++shapes.len;
        }
    }
}

// Вывод содержимого контейнера в указанный поток.
void Out(Shapes &shapes, ofstream &outputStream) {
    outputStream << "Elements in Shapes container: " << shapes.len << endl;
    for(int i = 0; i < shapes.len; ++i) {
        outputStream << i + 1 << ") ";
        Out(*(shapes.items[i]), outputStream);
    }
}

// Сортировка контейнера.
void Quicksort(Shapes &shapes, int first, int last) {
    int f = first;
    int l = last;
    Shape* mid = shapes.items[(f + l) / 2]; //вычисление опорного элемента

    do
    {
        while (Area(*shapes.items[f]) > Area(*mid)) {
            f++;
        }
        while (Area(*shapes.items[l]) < Area(*mid)) {
            l--;
        }

        if (f <= l) //перестановка элементов
        {
            Shape* temp = shapes.items[f];
            shapes.items[f] = shapes.items[l];
            shapes.items[l] = temp;
            f++;
            l--;
        }

    } while (f < l);

    if (first < l) {
        Quicksort(shapes, first, l);
    }
    if (f < last) {
        Quicksort(shapes, f, last);
    }
}
