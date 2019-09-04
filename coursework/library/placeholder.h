#ifndef PLACEHOLDER_H
#define PLACEHOLDER_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
#include <vector>

/**
    @brief �����, �������� ������ ����������� ����������� 
    @detail 
    
    ��������� ��� ���������� ��������� ��������� � ������� � �������� �����������, 
    �������� ���������� � ����������� ������
*/
class Placeholder {
public:

    Placeholder() = default;
    Placeholder(std::string name, std::map<std::string, cv::Mat>& image_set);
    ~Placeholder();

    /**
    @brief ��������� �����������, ���������� ������ ���������� � ������� ����������� �����������, ����������� ����� ��������
    @param other ������ �� ������ �����������
    */
    void concatenateImageSetTo(std::map<std::string, cv::Mat>& other);
private:

    std::string name_{""};
    std::map<std::string, cv::Mat> image_set_{ std::map<std::string, cv::Mat>()};
};


#endif 
