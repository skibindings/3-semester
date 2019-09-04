#ifndef BASEACTION_H
#define BASEACTION_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>

#include "logger.h"
#include "placeholder_storage.h"

/** @defgroup actions_module ƒоступные аугментации */

/**
    @brief –одительский класс единичной аугментации над изображени€ми
    @ingroup actions_module
*/

class BaseAction {
public:
    BaseAction();
    ~BaseAction();


    /**
        @brief —одержит логику метаморфозы, здесь, непосредственно, происходит обработка массивов изображений 
        @param placeholder_storage Ёкземл€р храналища @see Placeholder , необходимый дл€ взаимодействи€ с массивами изображений, временно хран€щимис€ в оперативной пам€ти
        @param src ¬ектор строк, указывающих, какие изображени€ должны быть подвергнуты метаморфозе
        @param settings  онтейнер, св€зывающий названи€ параметров и их значени€
        @param dst Cтрока, указывающа€, куда будет отправлены аугментированные изображени€
        @return ”спешность выполнени€ команды 
    */
    virtual int execute(PlaceholderStorage* placeholder_storage, 
                        std::vector<std::string> src,
                        std::map<std::string, std::string>& settings, 
                        std::string dst);

    std::string getName();

protected:

    void addSetting(std::string key, std::string default_value);
    
    std::map<std::string, cv::Mat> submitSrc(PlaceholderStorage* placeholder_storage, 
                                    std::vector<std::string>& src, 
                                    char constraints);
    std::string submitDst(PlaceholderStorage* placeholder_storage, std::string dst, char constraints);
    std::map<std::string, std::string> submitSettings(std::map<std::string, std::string>& settings);

    std::map<std::string, std::string> default_settings_;
    std::string name_;

    Logger log{*Logger::getInstance()};

    /// Ќабор возможных разрешений на src и dst операции
    enum Constraint : char {
        NONE = 0, ///< –азрешений нет
        /**
        < ¬ качестве источника изображений разрешены только Placeholder
        @see Placeholder
        */
        SRC_PLACEHOLDER = 1 << 0,
        SRC_PATH = 1 << 1, ///< ¬ качестве источника изображений разрешены только пути к каталогам и файлам из внешней пам€ти
        /**
        < ¬ качестве отправки обработанного массива изображений разрешЄн только Placeholder
        @see Placeholder
        */
        DST_PLACEHOLDER = 1 << 2,
        DST_PATH = 1 << 3, ///< ¬ качестве отправки обработанного массива изображений разрешЄн только только путь к каталогу из внешней пам€ти
        DEDAULT = SRC_PLACEHOLDER|SRC_PATH|DST_PLACEHOLDER|DST_PATH ///< ¬севозможные разрешени€
    };
};


#endif 
