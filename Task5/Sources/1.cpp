#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <thread>
#include <mutex>
#include <random>

using namespace std;

int writePos = 0; // Позиция в файле дял записи
int readPos = 0; // Позиция в файле для чтения
int writesCount = 0; // Количество произведённых записей в файл
int maxWritesCount = 10; // Требуемое количество записей в файл

mutex mtx;
random_device dev;
mt19937 rng(dev());
uniform_int_distribution<mt19937::result_type> dist6(0, 9);
string fileName;


void WriteInfo(int i)
{
    int num = i;

    while (true)
    {
        mtx.lock();
        bool exitCondition = writesCount >= maxWritesCount;
        mtx.unlock();
        if (exitCondition)
            return;

        mtx.lock();
        int rand = dist6(rng);
        cout << "Thread " << num << " write: " << rand << endl;

        ofstream out(fileName, ios::app);
        out << rand;
        out.close();

        writesCount += 1;
        mtx.unlock();

        this_thread::sleep_for(500ms); // Эмулирование вычислительной нагрузки
     }
}

void ReadInfo(int i)
{
    int num = i;

    while (true)
    {
        mtx.lock();
        bool exitCondition = readPos >= maxWritesCount;
        mtx.unlock();
        if (exitCondition)
            return;

        mtx.lock();
        if (writesCount > readPos)
        {
            char c;            

            ifstream in(fileName);
            in.seekg(readPos, ios::beg);
            in.get(c);
            in.close();

            // int n = c - '0';
            cout << "Thread " << num << " read: " << c << endl;
            readPos += 1;
        }
        mtx.unlock();
        

        this_thread::sleep_for(500ms); // Эмулирование вычислительной нагрузки
    }
}

int main()
{
    cout << "input path to file: ";
    //string file_path = "";
    getline(cin, fileName);
    cout << endl << fileName;
    
    int writeThreads = 4; // Количество потоков на запись
    int readThreads = 4; // Количество потоков на чтение

    if (std::filesystem::exists(fileName)) // Удаление файла, если он существует
        remove(fileName.c_str());

    for(int i = 0; i < writeThreads; i++)
    {
        thread t(WriteInfo, i);
        t.detach();
    }

    for (int i = 0; i < readThreads; i++)
    {
        thread t(ReadInfo, i);
        t.detach();
    }





    cin.get();
    cin.get();

    return 0;
}

