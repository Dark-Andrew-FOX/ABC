#include "Shapes.h"

// Очистка контейнера от элементов (освобождение памяти).
void Shapes::Clear() {
    for (int i = 0; i < lenght; ++i) {
        delete items[i];
    }
    lenght = 0;
}

// Ввод содержимого контейнера из указанного потока.
void Shapes::Input(ifstream& ifst) {
    while (!ifst.eof()) {
        //if ((items[lenght] = Shape::StaticIn(ifst)) != 0) {
        //    lenght++;
        //}

        int kind;
        ifst >> kind;

        double dencity;
        ifst >> dencity;

        switch (kind) {
            case 1:
                // Сфера.
            {
                // Прочитаем параметры фигуры.
                int radius;
                ifst >> radius;

                Shape *sphere = new Sphere(dencity, radius);
                items[lenght] = sphere;
            }
                break;
            case 2:
                // Параллелепипед.
            {
                // Прочитаем параметры фигуры.
                int a, b, c;
                ifst >> a >> b >> c;

                Shape *parallelepiped = new Parallelepiped(dencity, a, b, c);
                items[lenght] = parallelepiped;
            }
                break;
            case 3:
                // Правильный тетраэдр.
            {
                // Прочитаем параметры фигуры.
                int a;
                ifst >> a;

                Shape *rightTetrahedron = new RightTetrahedron(dencity, a);
                items[lenght] = rightTetrahedron;
            }
                break;
            default:
                // std::cout << "Some error during generation";
                break;
        }

        ++lenght;
    }
}

// Случайный ввод содержимого контейнера.
void Shapes::InputRandom(int size) {
    while (lenght < size) {
        // Сгенерируем тип фигуры.
        auto kind = rand() % 3 + 1;

        switch (kind) {
            case 1:
                // Сфера.
                {
                    // Сгенерируем параметры фигруы.
                    Shape *sphere = new Sphere();
                    items[lenght] = sphere;
                }
                break;
            case 2:
                // Параллелепипед.
                {
                    Shape *parallelepiped = new Parallelepiped();
                    items[lenght] = parallelepiped;
                }
                break;
            case 3:
                // Правильный тетраэдр.
                {
                    Shape *rightTetrahedron = new RightTetrahedron();
                    items[lenght] = rightTetrahedron;
                }
                break;
            default:
                // std::cout << "Some error during generation";
                break;
        }

        ++lenght;
    }
}

// Вывод содержимого контейнера в указанный поток.
void Shapes::Output(ofstream& ofst) {
    ofst << "Container contains " << lenght << " elements.\n";

    for (int i = 0; i < lenght; i++) {
        ofst << i + 1 << ") ";
        items[i]->Output(ofst);
    }
}

// Сортировка контейнера.
void Shapes::Quicksort(int first, int last) {
    int f = first;
    int l = last;
    Shape* mid = items[(f + l) / 2]; //вычисление опорного элемента

    do
    {
        while (items[f]->GetArea() > mid->GetArea()) {
            f++;
        }
        while (items[l]->GetArea() < mid->GetArea()) {
            l--;
        }

        if (f <= l) //перестановка элементов
        {
            Shape* temp = items[f];
            items[f] = items[l];
            items[l] = temp;
            f++;
            l--;
        }

    } while (f < l);

    if (first < l) {
        Quicksort(first, l);
    }
    if (f < last) {
        Quicksort(f, last);
    }
}