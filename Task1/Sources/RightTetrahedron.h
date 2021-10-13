#ifndef __RightTetrahedron__
#define __RightTetrahedron__

#include <fstream>
#include "Randomize.h"
using namespace std;

struct RightTetrahedron {
    int length_of_edge;
};

// ���� ���������� ����������� ��������� �� �����.
void In(RightTetrahedron& rightTetrahedron, ifstream& inputStream);

// ��������� ���� ���������� ����������� ���������.
void InRnd(RightTetrahedron& rightTetrahedron);

// ����� ���������� ����������� ��������� � ������������� �����.
void Out(RightTetrahedron& rightTetrahedron, ofstream& outputStream);

double Area(RightTetrahedron& rightTetrahedron);

#endif