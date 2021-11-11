from Shapes import Shapes
import sys
import time


def main():
    input_file_name = None
    output_file_name = None
    shapes_count = 5
    mode = None

    shapes = Shapes()

    if len(sys.argv) == 4:
        # Обычный запуск программы.

        # Назначим выходной файл.
        output_file_name = sys.argv[3]

        # Определим режим ввода.
        mode = sys.argv[1]
        if mode == "file":
            # Ввод из файла.
            input_file_name = sys.argv[2]

            with open(input_file_name, 'r') as file:
                shapes.input(file)
        else:
            # Случайная генерация.
            shapes_count = int(sys.argv[2])

            # Проверим на правильность ввода.
            if shapes_count > 10000 or shapes_count < 0:
                print("INPUT ERROR! Max number of shapes is 10000 and min number of shapes is 0.")
                return -1

            # Засечём время.
            start_time = time.time()
            print("GENERATION STARTED")

            # Заполненим контейнер генератором случайных чисел.
            shapes.input_random(shapes_count)

            # Вывод времени.
            print("Time of generation is ", (time.time() - start_time), "seconds")

    else:
        # Ввод некорректен, завершаем работу.
        print("INPUT ERROR! Please use this format for input:")
        print("<program name> <file> <path to input file> <path to output file>")
        print("OR")
        print("<program name> <random> <number of shapes to create> <path to output file>")
        return

    # Вывод содержимого контейнера.
    with open(output_file_name, 'w') as file:
        shapes.output(file)

    # Выполнение функции - Сортировка контейнера.
    # Засечём время.
    start_time = time.time()
    print("SORT STARTED")

    shapes.quicksort(0, shapes.length - 1)

    # Вывод времени.
    print("Time of sorting is ", (time.time() - start_time), "seconds")

    # Вывод содержимого контейнера.
    with open(output_file_name, 'a') as file:
        shapes.output(file)

    # Очистка памяти и завершение работы программы.
    # shapes.clear()
    print("END OF PROGRAM")
    return


if __name__ == "__main__":
    main()
