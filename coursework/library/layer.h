#ifndef LAYER_H
#define LAYER_H

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <stdio.h>
#include "json.h"

/**
    @brief Формальный класс, описывающий операцию над изображениями
    @details В данный класс помещается вся информация о единичной операции в строковом представлении
*/

class Layer {
public:
    /**
    @private
    */
    Layer() = default;
    /**
    @brief Конструктор класса
    @param Объект действия
    */
    Layer(const nlohmann::json& j);
    /**
    @private
    */
    ~Layer();

    /**
    @private
    */
    std::string getAction();
    /**
    @private
    */
    std::vector<std::string> getSrc();
    /**
    @private
    */
    std::string getDst();

    /**
    @private
    */
    std::map<std::string, std::string> getSettings();

    /**
    @private
    */
    void debugPrint();

private:
    /// Название действия
    std::string action_{""};
    /// Список источников, из которых будет составляться массив изображений, далее отправляемый на обработку
    std::vector<std::string> src_{std::vector<std::string>()};
    /// Строка, указывающая, куда отправлять обработнный массив изображений : @see Placeholder или во внешнее хранилище
    std::string dst_{""};
    /// Контейнер, связывающий названия параметров и их значения
    std::map<std::string, std::string> settings_{std::map<std::string, std::string>()};
};


#endif 
