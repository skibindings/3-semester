#ifndef PLACEHOLDER_H
#define PLACEHOLDER_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
#include <vector>

/**
    @brief Класс, хранящий массив именованных изображений 
    @detail 
    
    Необходим для построения пайплайна обработки и доступа к массивам изображений, 
    временно хранящихся в оперативной памяти
*/
class Placeholder {
public:

    Placeholder() = default;
    Placeholder(std::string name, std::map<std::string, cv::Mat>& image_set);
    ~Placeholder();

    /**
    @brief Добавляет изображения, хранящиеся внутри экземлпяра к массиву именованных изображений, переданному через аргумент
    @param other Ссылка на массив изображений
    */
    void concatenateImageSetTo(std::map<std::string, cv::Mat>& other);
private:

    std::string name_{""};
    std::map<std::string, cv::Mat> image_set_{ std::map<std::string, cv::Mat>()};
};


#endif 
