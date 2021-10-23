//
// Created by super on 23.10.2021.
//

#include "RightTetrahedron.h"

double RightTetrahedron::GetArea() {
    return sqrt(3) * ((long long)length_of_edge * (long long)length_of_edge);
}

void RightTetrahedron::Output(ofstream &outputStream) {
    outputStream << "This is Right Tetrahedron: length_of_edge = " << length_of_edge;
    Shape::Output(outputStream);
}
