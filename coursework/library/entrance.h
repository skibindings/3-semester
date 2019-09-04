#ifndef ENTRANCE_H
#define ENTRANCE_H

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include "json.h"
#include "layer.h"
#include "actions_factory.h"
#include "logger.h"

using namespace std;
using namespace nlohmann;
using namespace cv;

/**
    @brief Функция обработки файла-конфигурации

    @param config Путь к файлу конфигурации

    @return Статус выполнения функции
*/
int processPipeline(string configPath) {
    string configName(configPath);  // by default
    Logger& log = *Logger::getInstance();
    log.setPath("log_output.txt");

    if (configName != "") {
        std::ifstream i(configName);
        ActionsFactory* actionsFactory = new ActionsFactory();
        json j;
        try {
            i >> j;
        }
        catch (const json::parse_error& e) {
            log << e.what() << "\n";
            return EXIT_FAILURE;
        }
        catch (const json::type_error& e) {
            log << e.what() << "\n";
            return EXIT_FAILURE;
        }
        catch (const json::out_of_range& e) {
            log << e.what() << "\n";
            return EXIT_FAILURE;
        }

        for (int i = 0; i < j.size(); i++) {
            Layer l;
            try {
                l = Layer(j.at(i));
            }
            catch (const json::parse_error& e) {
                log << e.what() << "\n";
                return EXIT_FAILURE;
            }
            catch (const json::type_error& e) {
                log << e.what() << "\n";
                return EXIT_FAILURE;
            }
            catch (const json::out_of_range& e) {
                log << e.what() << "\n";
                return EXIT_FAILURE;
            }

            l.debugPrint();
            int error_status = actionsFactory->processLayer(&l);
            if (error_status == EXIT_FAILURE) {
                delete actionsFactory;
                return EXIT_FAILURE;
            }
        }
        delete actionsFactory;
    }

    return EXIT_SUCCESS;
}

/**
    @brief Функция генерирует шаблон файла конфигурации

    @param config Путь к файлу конфигурации

    @return Статус выполнения функции
*/
int generateConfigSample(string sampleName) {
    ofstream sample;
    sample.open(sampleName + ".json");

    if (sample.is_open()) {
        sample << "[" << endl;
        sample << "\t{" << endl;
        sample << "\t\t\"action\": \"<first_action>\"," << endl;
        sample << "\t\t\"src\": [" << endl;
        sample << "\t\t\t\"<input_1>\"," << endl;
        sample << "\t\t\t\"<input_2>\"," << endl;
        sample << "\t\t\t\"<input_..>\"" << endl;
        sample << "\t\t\]," << endl;
        sample << "\t\t\"dst\": \"<output>\"," << endl;
        sample << "\t\t\"settings\": {" << endl;
        sample << "\t\t\t\"<first_setting>\": \"value\"," << endl;
        sample << "\t\t\t\"<second_setting>\": \"value\"," << endl;
        sample << "\t\t\t\"<.._setting>\": \"value\"" << endl;
        sample << "\t\t}" << endl;
        sample << "\t}," << endl;

        sample << "\t{" << endl;
        sample << "\t\t\"action\": \"<second_action>\"," << endl;
        sample << "\t\t\"src\": [" << endl;
        sample << "\t\t\t\"<input_1>\"," << endl;
        sample << "\t\t\t\"<input_2>\"," << endl;
        sample << "\t\t\t\"<input_..>\"" << endl;
        sample << "\t\t\]," << endl;
        sample << "\t\t\"dst\": \"<output>\"," << endl;
        sample << "\t\t\"settings\": {" << endl;
        sample << "\t\t\t\"<first_setting>\": \"value\"," << endl;
        sample << "\t\t\t\"<second_setting>\": \"value\"," << endl;
        sample << "\t\t\t\"<.._setting>\": \"value\"" << endl;
        sample << "\t\t}" << endl;
        sample << "\t}," << endl;

        sample << "\t{" << endl;
        sample << "\t\t\"action\": \"<.._action>\"," << endl;
        sample << "\t\t\"src\": [" << endl;
        sample << "\t\t\t\"<input_1>\"," << endl;
        sample << "\t\t\t\"<input_2>\"," << endl;
        sample << "\t\t\t\"<input_..>\"" << endl;
        sample << "\t\t\]," << endl;
        sample << "\t\t\"dst\": \"<output>\"," << endl;
        sample << "\t\t\"settings\": {" << endl;
        sample << "\t\t\t\"<first_setting>\": \"value\"," << endl;
        sample << "\t\t\t\"<second_setting>\": \"value\"," << endl;
        sample << "\t\t\t\"<.._setting>\": \"value\"" << endl;
        sample << "\t\t}" << endl;
        sample << "\t}" << endl;
        sample << "]" << endl;
    }
    else {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

#endif  // ENTRANCE_H
