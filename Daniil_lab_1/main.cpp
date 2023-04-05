#include "LogDuration.h"
#include "FrequencyCounter.h"
#include "tests.h"

#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("chcp 1251");
    try {
        RunTests();
        cout << "Введите путь до файла: ";
        string path{};
        getline(cin, path);
        FrequencyCounter counter(path);

        LogDuration time_counter("Время ");

        double frequency = counter.GetRussianWordsFrequency();
        cout << "Частота русских слов в файле: " << frequency << endl;
    } 
    catch (const exception& exception) {
        cout << exception.what() << endl;
        return EXIT_FAILURE;
    }

    return 0;
}

