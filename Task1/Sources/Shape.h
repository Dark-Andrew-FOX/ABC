#ifndef __shape__
#define __shape__

#include "Sphere.h"
#include "Parallelepiped.h"
#include "RightTetrahedron.h"
#include "Randomize.h"

// ���������, ���������� ��� ��������� ������.
enum ShapeType { SPHERE = 1, PARALLELEPIPED = 2, RIGHT_TETRAHEDRON = 3 };

struct Shape {
    //ShapeType stype;
    // ��� ������.
    int stype;

    union {
        Sphere sphere;
        Parallelepiped parallelepiped;
        RightTetrahedron rightTetrahedron;
    };

    // ����� ��������������.
    // ��������� ���������.
    double p;
};

// ���� ���������� ������.
Shape* In(ifstream& inputStream);

// ��������� ���� ���������� ������.
Shape* InRnd();

// ����� ���������� ������.
void Out(Shape& shape, ofstream& outputStream);

// ���������� ������� ���������� ������.
double Area(Shape& shape);

#endif
