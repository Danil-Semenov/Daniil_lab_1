#include "LogDuration.h"
#include "FrequencyCounter.h"
#include "tests.h"

#include <iostream>
#include <Windows.h>

using namespace std;

int main(int argc, const char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (argc != 2) {
        std::cerr << "Требуется передать параметр - путь к файлу. "sv << std::endl;
        return EXIT_FAILURE;
    }

    try {
        RunTests();
        FrequencyCounter counter(argv[1]);

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

