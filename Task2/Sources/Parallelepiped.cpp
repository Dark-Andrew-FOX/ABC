#include "Parallelepiped.h"

double Parallelepiped::GetArea() {
    return 2 * (first_edge * second_edge
                + second_edge * third_edge
                + first_edge * third_edge);
}

void Parallelepiped::Output(ofstream &outputStream) {
    outputStream << "This is Parallelepiped: first_edge = " << first_edge
                 << "; second_edge = " << second_edge
                 << "; third_edge = " << third_edge;
    Shape::Output(outputStream);
}
