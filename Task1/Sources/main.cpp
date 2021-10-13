// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Shapes.h"

#include <ctime>

int main(int argc, char* argv[]) {
    string inputFilename;
    string outputFilename;
    int shapesCount = 5;
    string mode;

    
    bool debug = false;
    if (debug) {
        // Если включён режим дебага.
        cout << "DEBUG MODE HAS BEEN ACTIVATED" << endl;

        mode = "file";
        inputFilename = "C:\\Users\\super\\source\\repos\\Task1\\Debug\\tests\\test01.txt";
        outputFilename = "C:\\Users\\super\\source\\repos\\Task1\\Debug\\tests\\test01out.txt";
    }
    else if (argc < 4 /*|| !(argv[1] == "file" || argv[1] == "random")*/) {
        // Если недостаточно аргументов.
        cout << "INPUT ERROR! Please use this format for input:" << endl << endl
            << "<program name> <file> <path to input file> <path to output file>" << endl
            << "OR" << endl
            << "<program name> <random> <number of shapes to create> <path to output file>" << endl << endl;
        return -1;
    }
    else {
        // Если обычный запуск программы.

        // Определение режима ввода.
        mode = argv[1];
        if (mode == "file") {
            inputFilename = argv[2];
        }
        else {
            shapesCount = atoi(argv[2]);
            if (shapesCount > 10000) {
                cout << "INPUT ERROR! max number of shapes is 10000" << endl;
                return -1;
            }
        }
        outputFilename = argv[3];
    }

    Shapes shapes;
    Init(shapes);

    if (mode == "file") {
        // Загрузить из файла.
        ifstream inputStream(inputFilename);
        if (!inputStream) {
            cout << "FILE OPENING ERROR" << endl;
            return -1;
        }
        In(shapes, inputStream);
    }
    else {
        // Загрузить случайные числа.

        // системные часы в качестве инициализатора.
        srand(static_cast<unsigned int>(time(0)));


        clock_t start = clock();

        // Заполнение контейнера генератором случайных чисел.
        InRnd(shapes, shapesCount);

        clock_t end = clock();
        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "Time of generation is " << seconds << " seconds." << endl;
    }

    // Вывод содержимого контейнера.
    ofstream outputStream(outputFilename);
    Out(shapes, outputStream);

    // Выполнение функции.
    // Сортировка контейнера.
    cout << "SORT STARTED" << endl;
    clock_t start = clock();

    Quicksort(shapes, 0, shapes.len - 1);

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    Out(shapes, outputStream);
    cout << "Time of sorting is " << seconds << " seconds." << endl;

    // Очистка памяти и завершение работы программы.
    Clear(shapes);
    cout << "END OF PROGRAM" << endl;
    return 0;
}
