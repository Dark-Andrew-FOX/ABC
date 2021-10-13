#include "RightTetrahedron.h"

// Ввод параметров правильного тетраэдра из файла
void In(RightTetrahedron& rightTetrahedron, ifstream& inputStream) {
    inputStream >> rightTetrahedron.length_of_edge;
}

// Случайный ввод параметров параллелепипеда.
void InRnd(RightTetrahedron& rightTetrahedron) {
    rightTetrahedron.length_of_edge = Random();
}

// Вывод параметров правильного тетраэдра в форматируемый поток
void Out(RightTetrahedron& rightTetrahedron, ofstream& outputStream) {
    outputStream << "This is Right Tetrahedron: length_of_edge = " << rightTetrahedron.length_of_edge;
}

// Подсчёт площади правильного тетраэдра. (корень из 3)*(длина_ребра в квадрате)
double Area(RightTetrahedron& rightTetrahedron) {
    return sqrt(3) * ((long long)rightTetrahedron.length_of_edge * (long long)rightTetrahedron.length_of_edge);
}