#include "Sphere.h"

//------------------------------------------------------------------------------
// Ввод параметров сферы из файла
void In(Sphere& sphere, ifstream& inputStream) {
    inputStream >> sphere.r;
}

// Случайный ввод параметров прямоугольника
void InRnd(Sphere& sphere) {
    sphere.r = Random();
}

// Вывод параметров сферы в форматируемый поток
void Out(Sphere& sphere, ofstream& outputStream) {
    outputStream << "This is Sphere: radius = " << sphere.r;
}

double Area(Sphere& sphere) {
    return 4 * M_PI * sphere.r * sphere.r;
}