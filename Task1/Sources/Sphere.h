#ifndef __sphere__
#define __sphere__

#include <fstream>
#include "Randomize.h"

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

struct Sphere {
    // Радиус.
    int r;
};

// Ввод параметров шара из файла.
void In(Sphere& sphere, ifstream& inputStream);

// Случайный ввод параметров шара.
void InRnd(Sphere& sphere);

// Вывод параметров шара в форматируемый поток.
void Out(Sphere& sphere, ofstream& outputStream);

double Area(Sphere& sphere);

#endif