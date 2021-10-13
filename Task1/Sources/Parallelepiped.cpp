#include "Parallelepiped.h"

// Ввод параметров параллелепипеда из файла
void In(Parallelepiped& parallelepiped, ifstream& inputStream) {
    inputStream >> parallelepiped.first_edge 
        >> parallelepiped.second_edge 
        >> parallelepiped.third_edge;
}

// Случайный ввод параметров параллелепипеда.
void InRnd(Parallelepiped& parallelepiped) {
    parallelepiped.first_edge = Random();
    parallelepiped.second_edge = Random();
    parallelepiped.third_edge = Random();
}

// Вывод параметров параллелепипеда в форматируемый поток
void Out(Parallelepiped& parallelepiped, ofstream& outputStream) {
    outputStream << "This is Parallelepiped: first_edge = " << parallelepiped.first_edge
        << "; second_edge = " << parallelepiped.second_edge 
        << "; third_edge = " << parallelepiped.third_edge;
}

// Подсчёт площади параллелепипеда.
double Area(Parallelepiped& par) {
    return 2 * (par.first_edge * par.second_edge 
        + par.second_edge * par.third_edge 
        + par.first_edge * par.third_edge);
}