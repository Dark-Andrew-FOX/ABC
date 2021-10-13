#include "Shape.h"

// Ввод параметров обобщенной фигуры из файла.
Shape* In(ifstream& inputStream) {
    Shape* shape;
    shape = new Shape;
    int shapeType;
    inputStream >> shapeType;
    inputStream >> shape->p;

    switch (shapeType) {
        case ShapeType::SPHERE:
            shape->stype = ShapeType::SPHERE;
            In(shape->sphere, inputStream);
            return shape;

        case ShapeType::PARALLELEPIPED:
            shape->stype = ShapeType::PARALLELEPIPED;
            In(shape->parallelepiped, inputStream);
            return shape;

        case ShapeType::RIGHT_TETRAHEDRON:
            shape->stype = ShapeType::RIGHT_TETRAHEDRON;
            In(shape->rightTetrahedron, inputStream);
            return shape;

        default:
            return 0;
    }
}

// Случайный ввод обобщенной фигуры.
Shape* InRnd() {
    Shape* shape = new Shape();
    // Генерируем общий признак.
    shape->p = Random();

    // Генерируем тип фигуры.
    auto k = rand() % 3 + 1;
    switch (k) {
        case ShapeType::SPHERE:
            //shape = new Shape;
            shape->stype = ShapeType::SPHERE;
            InRnd(shape->sphere);
            return shape;

        case ShapeType::PARALLELEPIPED:
            //shape = new Shape;
            shape->stype = ShapeType::PARALLELEPIPED;
            InRnd(shape->parallelepiped);
            return shape;

        case ShapeType::RIGHT_TETRAHEDRON:
            //shape = new Shape;
            shape->stype = ShapeType::RIGHT_TETRAHEDRON;
            InRnd(shape->rightTetrahedron);
            return shape;

        default:
            return 0;
    }
}

// Вывод параметров текущей фигуры в поток.
void Out(Shape& shape, ofstream& outputStream) {
    switch (shape.stype) {
        case ShapeType::SPHERE:
            Out(shape.sphere, outputStream);
            break;

        case ShapeType::PARALLELEPIPED:
            Out(shape.parallelepiped, outputStream);
            break;

        case ShapeType::RIGHT_TETRAHEDRON:
            Out(shape.rightTetrahedron, outputStream);
            break;

        default:
            outputStream << "Incorrect figure!" << endl;
            return;
    }
    outputStream << "; Density = " << shape.p;
    outputStream << "; Area = " << Area(shape) << endl;
}

double Area(Shape& shape) {
    switch (shape.stype) {
        case ShapeType::SPHERE:
            return Area(shape.sphere);

        case ShapeType::PARALLELEPIPED:
            return Area(shape.parallelepiped);

        case ShapeType::RIGHT_TETRAHEDRON:
            return Area(shape.rightTetrahedron);

        default:
            return 0.0;
    }
}