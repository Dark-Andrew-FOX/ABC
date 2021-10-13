#ifndef __RightTetrahedron__
#define __RightTetrahedron__

#include <fstream>
#include "Randomize.h"
using namespace std;

struct RightTetrahedron {
    int length_of_edge;
};

// Ввод параметров правильного тетраэдра из файла.
void In(RightTetrahedron& rightTetrahedron, ifstream& inputStream);

// Случайный ввод параметров правильного тетраэдра.
void InRnd(RightTetrahedron& rightTetrahedron);

// Вывод параметров правильного тетраэдра в форматируемый поток.
void Out(RightTetrahedron& rightTetrahedron, ofstream& outputStream);

double Area(RightTetrahedron& rightTetrahedron);

#endif