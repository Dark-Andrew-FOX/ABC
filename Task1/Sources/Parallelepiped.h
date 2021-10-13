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

// Ввод параметров параллелепипеда из файла.
void In(Parallelepiped& parallelepiped, ifstream& inputStream);

// Случайный ввод параметров параллелепипеда.
void InRnd(Parallelepiped& parallelepiped);

// Вывод параметров параллелепипеда в форматируемый поток.
void Out(Parallelepiped& parallelepiped, ofstream& outputStream);

double Area(Parallelepiped& parallelepiped);

#endif