#include <stdio.h>
#include <iostream>
#include <fstream>

#include <library/entrance.h>

using namespace std;

/**
    @brief Входная точка программы
    @details Исполнение программы начинается здесь

    @param argc Количество аргументов
    @param argv Список аргументов
    
    Ожидаемый аргумент - строка, содержащая путь json файлу конфигурации

    @return Статус завершения программы
*/
int main(int argc, char** argv) {
    string configName("");  // by default
    if (argc > 1) {
        configName = argv[1];
    }
    //configName = "C:/Users/minea/Desktop/test_1.json";
    cout << configName << endl;

    if (!configName.empty())
        return processPipeline(configName);
    else
        return generateConfigSample("sample");
}
