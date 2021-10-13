#ifndef __shape__
#define __shape__

#include "Sphere.h"
#include "Parallelepiped.h"
#include "RightTetrahedron.h"
#include "Randomize.h"

// Структура, обобщающая все имеющиеся фигуры.
enum ShapeType { SPHERE = 1, PARALLELEPIPED = 2, RIGHT_TETRAHEDRON = 3 };

struct Shape {
    //ShapeType stype;
    // Тип фигуры.
    int stype;

    union {
        Sphere sphere;
        Parallelepiped parallelepiped;
        RightTetrahedron rightTetrahedron;
    };

    // Общие характеристики.
    // Плотность материала.
    double p;
};

// Ввод обобщенной фигуры.
Shape* In(ifstream& inputStream);

// Случайный ввод обобщенной фигуры.
Shape* InRnd();

// Вывод обобщенной фигуры.
void Out(Shape& shape, ofstream& outputStream);

// Нахождение площади обобщенной фигуры.
double Area(Shape& shape);

#endif
