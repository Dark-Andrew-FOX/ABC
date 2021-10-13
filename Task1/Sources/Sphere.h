#ifndef __sphere__
#define __sphere__

#include <fstream>
#include "Randomize.h"

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

struct Sphere {
    // ������.
    int r;
};

// ���� ���������� ���� �� �����.
void In(Sphere& sphere, ifstream& inputStream);

// ��������� ���� ���������� ����.
void InRnd(Sphere& sphere);

// ����� ���������� ���� � ������������� �����.
void Out(Sphere& sphere, ofstream& outputStream);

double Area(Sphere& sphere);

#endif