#ifndef ABC2_RIGHTTETRAHEDRON_H
#define ABC2_RIGHTTETRAHEDRON_H

#include "Shape.h"
#include <fstream>

using namespace std;


class RightTetrahedron : public Shape {
public:
    int length_of_edge;

    RightTetrahedron(double density, int length_of_edge) : Shape(density)
    {
        this->length_of_edge = length_of_edge;
    }

    // Конструктор для случайной генерации.
    RightTetrahedron() : Shape(){
        length_of_edge = Random();
    }

    // Унаследовано через Shape.
    double GetArea() override;

    // Вывод параметров шара в форматируемый поток.
    void Output(ofstream& outputStream) override;
};


#endif //ABC2_RIGHTTETRAHEDRON_H
