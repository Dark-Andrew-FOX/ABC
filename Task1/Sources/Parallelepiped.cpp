#include "Parallelepiped.h"

// ���� ���������� ��������������� �� �����
void In(Parallelepiped& parallelepiped, ifstream& inputStream) {
    inputStream >> parallelepiped.first_edge 
        >> parallelepiped.second_edge 
        >> parallelepiped.third_edge;
}

// ��������� ���� ���������� ���������������.
void InRnd(Parallelepiped& parallelepiped) {
    parallelepiped.first_edge = Random();
    parallelepiped.second_edge = Random();
    parallelepiped.third_edge = Random();
}

// ����� ���������� ��������������� � ������������� �����
void Out(Parallelepiped& parallelepiped, ofstream& outputStream) {
    outputStream << "This is Parallelepiped: first_edge = " << parallelepiped.first_edge
        << "; second_edge = " << parallelepiped.second_edge 
        << "; third_edge = " << parallelepiped.third_edge;
}

// ������� ������� ���������������.
double Area(Parallelepiped& par) {
    return 2 * (par.first_edge * par.second_edge 
        + par.second_edge * par.third_edge 
        + par.first_edge * par.third_edge);
}