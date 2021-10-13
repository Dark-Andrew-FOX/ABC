#include "RightTetrahedron.h"

// ���� ���������� ����������� ��������� �� �����
void In(RightTetrahedron& rightTetrahedron, ifstream& inputStream) {
    inputStream >> rightTetrahedron.length_of_edge;
}

// ��������� ���� ���������� ���������������.
void InRnd(RightTetrahedron& rightTetrahedron) {
    rightTetrahedron.length_of_edge = Random();
}

// ����� ���������� ����������� ��������� � ������������� �����
void Out(RightTetrahedron& rightTetrahedron, ofstream& outputStream) {
    outputStream << "This is Right Tetrahedron: length_of_edge = " << rightTetrahedron.length_of_edge;
}

// ������� ������� ����������� ���������. (������ �� 3)*(�����_����� � ��������)
double Area(RightTetrahedron& rightTetrahedron) {
    return sqrt(3) * ((long long)rightTetrahedron.length_of_edge * (long long)rightTetrahedron.length_of_edge);
}