#ifndef ABC2_PARALLELEPIPED_H
#define ABC2_PARALLELEPIPED_H


#include "Shape.h"
#include <fstream>

using namespace std;

class Parallelepiped : public Shape {
public:
    int first_edge;
    int second_edge;
    int third_edge;

    Parallelepiped(double density, int first_edge, int second_edge, int third_edge) : Shape(density)
    {
        this->first_edge = first_edge;
        this->second_edge = second_edge;
        this->third_edge = third_edge;
    }

    // Конструктор для случайной генерации.
    Parallelepiped() : Shape(){
        first_edge = Random();
        second_edge = Random();
        third_edge = Random();
    }

    // Унаследовано через Shape.
    double GetArea() override;

    // Вывод параметров шара в форматируемый поток.
    void Output(ofstream& outputStream) override;
};


#endif //ABC2_PARALLELEPIPED_H
