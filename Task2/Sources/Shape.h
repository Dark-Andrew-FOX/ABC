#ifndef ABC2_SHAPE_H
#define ABC2_SHAPE_H

#include <fstream>
#include "Randomize.h"
using namespace std;

class Shape {
public:

    // Общий признак - плотность фигуры.
    double density;

    // Базовый конструктор.
    Shape(double density) {
        this->density = density;
    }

    // Базовый конструкор для случайной генерации.
    Shape() {
        density = Random();
    }

    // Базовый деструктор.
    virtual ~Shape() {};

    // Виртуальный метод вывода фигуры.
    virtual void Output(ofstream& outputStream) {
        outputStream << "; density = " << density << "; Area = " << GetArea() << endl;
    };

    // Виртуальный метод получения площади фигуры.
    virtual double GetArea() = 0;
};


#endif //ABC2_SHAPE_H
