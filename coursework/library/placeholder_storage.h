#ifndef PLACEHOLDERSTORAGE_H
#define PLACEHOLDERSTORAGE_H

#include <iostream>
#include <sstream>
#include <vector>
#include "dirent.h"

#include "placeholder.h"
#include "logger.h"

/**
    @brief  ласс предназначен дл€ хранени€ Placeholder
    @see Placeholder
*/
class PlaceholderStorage {
public:

    PlaceholderStorage();
    ~PlaceholderStorage();

    /**
    @param src —писок источников, из которых образуетс€ массив именованных изображений
    @return ћассив именованных изображений
    */
    std::map <std::string, cv::Mat> srcToImageSet(std::vector<std::string>& src);
    /**
    @brief —оздает новый @see Placeholder и возвращает указатель на него
    @param name Ќазвание нового @see Placeholder
    @return ћассив именованных изображений нового @see Placeholder
    */
    Placeholder* createPlaceholder(std::string name, std::map<std::string, cv::Mat> image_set);
    /**
    @brief ѕровер€ет, имеет ли указанна€ строка формат @see Placeholder "$placeholder_name"
    @param str —трока, которую нужно проверить
    @return »меет ли формат @see Placeholder "$placeholder_name"
    */
    bool isPlaceholderFormat(std::string str);
private:

    bool placeholderExists(std::string name);

    std::map<std::string, Placeholder*> placeholders_;

    Logger log{ *Logger::getInstance() };
};


#endif 
