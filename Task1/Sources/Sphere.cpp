#include "Sphere.h"

//------------------------------------------------------------------------------
// ���� ���������� ����� �� �����
void In(Sphere& sphere, ifstream& inputStream) {
    inputStream >> sphere.r;
}

// ��������� ���� ���������� ��������������
void InRnd(Sphere& sphere) {
    sphere.r = Random();
}

// ����� ���������� ����� � ������������� �����
void Out(Sphere& sphere, ofstream& outputStream) {
    outputStream << "This is Sphere: radius = " << sphere.r;
}

double Area(Sphere& sphere) {
    return 4 * M_PI * sphere.r * sphere.r;
}