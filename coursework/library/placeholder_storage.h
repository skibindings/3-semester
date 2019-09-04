#ifndef PLACEHOLDERSTORAGE_H
#define PLACEHOLDERSTORAGE_H

#include <iostream>
#include <sstream>
#include <vector>
#include "dirent.h"

#include "placeholder.h"
#include "logger.h"

/**
    @brief ����� ������������ ��� �������� Placeholder
    @see Placeholder
*/
class PlaceholderStorage {
public:

    PlaceholderStorage();
    ~PlaceholderStorage();

    /**
    @param src ������ ����������, �� ������� ���������� ������ ����������� �����������
    @return ������ ����������� �����������
    */
    std::map <std::string, cv::Mat> srcToImageSet(std::vector<std::string>& src);
    /**
    @brief ������� ����� @see Placeholder � ���������� ��������� �� ����
    @param name �������� ������ @see Placeholder
    @return ������ ����������� ����������� ������ @see Placeholder
    */
    Placeholder* createPlaceholder(std::string name, std::map<std::string, cv::Mat> image_set);
    /**
    @brief ���������, ����� �� ��������� ������ ������ @see Placeholder "$placeholder_name"
    @param str ������, ������� ����� ���������
    @return ����� �� ������ @see Placeholder "$placeholder_name"
    */
    bool isPlaceholderFormat(std::string str);
private:

    bool placeholderExists(std::string name);

    std::map<std::string, Placeholder*> placeholders_;

    Logger log{ *Logger::getInstance() };
};


#endif 
