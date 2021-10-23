#ifndef ABC2_SPHERE_H
#define ABC2_SPHERE_H


#define _USE_MATH_DEFINES
#include <fstream>
#include <cmath>

#include "Shape.h"
using namespace std;


class Sphere : public Shape {
public:
    // Радиус.
    int radius;

    // Конструктор.
    Sphere(double density, int radius) : Shape(density)
    {
        this->radius = radius;
    }

    // Конструктор для случайной генерации.
    Sphere() : Shape()
    {
        radius = Random();
    }

    //// Ввод параметров шара из файла.
    //void In(Sphere& sphere, ifstream& inputStream);

    // Унаследовано через Shape.
    double GetArea() override;

    // Вывод параметров шара в форматируемый поток.
    void Output(ofstream& outputStream) override;
};


#endif //ABC2_SPHERE_H
