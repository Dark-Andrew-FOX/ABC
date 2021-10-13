#ifndef __Parallelepiped__
#define __Parallelepiped__

#include <fstream>
#include "Randomize.h"
using namespace std;

struct Parallelepiped {
    int first_edge;
    int second_edge;
    int third_edge;
};

// ���� ���������� ��������������� �� �����.
void In(Parallelepiped& parallelepiped, ifstream& inputStream);

// ��������� ���� ���������� ���������������.
void InRnd(Parallelepiped& parallelepiped);

// ����� ���������� ��������������� � ������������� �����.
void Out(Parallelepiped& parallelepiped, ofstream& outputStream);

double Area(Parallelepiped& parallelepiped);

#endif