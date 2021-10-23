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

    Shapes shapes;

    if (argc == 4 /*&& (argv[1] == "file" || argv[1] == "random")*/) {
        // Обычный запуск программы.

        // Назначим выходной файл.
        outputFilename = argv[3];

        // Определим режим ввода.
        mode = argv[1];
        if (mode == "file") {
            // Ввод из файла.
            inputFilename = argv[2];

            ifstream inputStream(inputFilename);

            // Проверим на правильность ввода.
            if (!inputStream) {
                cout << "FILE OPENING ERROR!" << endl;
                return -1;
            }

            shapes.Input(inputStream);
        }
        else {
            // Случайная генерация.
            shapesCount = atoi(argv[2]);

            // Проверим на правильность ввода.
            if (shapesCount > 10000 || shapesCount < 0) {
                cout << "INPUT ERROR! Max number of shapes is 10000 and min number of shapes is 0." << endl;
                return -1;
            }

            // системные часы в качестве инициализатора.
            srand(static_cast<unsigned int>(time(0)));

            // Засечём время.
            cout << "GENERATION STARTED" << endl;
            clock_t start = clock();

            // Заполненим контейнер генератором случайных чисел.
            shapes.InputRandom(shapesCount);

            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "Time of generation is " << seconds << " seconds." << endl;
        }
    }
    else {
        // Ввод некорректен, завершаем работу.
        cout << "INPUT ERROR! Please use this format for input:" << endl << endl
             << "<program name> <file> <path to input file> <path to output file>" << endl
             << "OR" << endl
             << "<program name> <random> <number of shapes to create> <path to output file>" << endl << endl;
        return -1;
    }

    // Вывод содержимого контейнера.
    ofstream outputStream(outputFilename);
    shapes.Output(outputStream);

    // Выполнение функции - Сортировка контейнера.
    // Засечём время.
    cout << "SORT STARTED" << endl;
    clock_t start = clock();

    shapes.Quicksort(0, shapes.GetLength() - 1);

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    cout << "Time of sorting is " << seconds << " seconds." << endl;
    shapes.Output(outputStream);

    // Очистка памяти и завершение работы программы.
    shapes.Clear();
    cout << "END OF PROGRAM" << endl;
    return 0;
}
