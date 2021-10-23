#include "Sphere.h"

double Sphere::GetArea() {
    return 4 * M_PI * radius * radius;
}

void Sphere::Output(ofstream &outputStream) {
    outputStream << "This is Sphere: radius = " << radius;
    Shape::Output(outputStream);
}
