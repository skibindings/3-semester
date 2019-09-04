#ifndef LAYER_H
#define LAYER_H

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <stdio.h>
#include "json.h"

/**
    @brief ���������� �����, ����������� �������� ��� �������������
    @details � ������ ����� ���������� ��� ���������� � ��������� �������� � ��������� �������������
*/

class Layer {
public:
    /**
    @private
    */
    Layer() = default;
    /**
    @brief ����������� ������
    @param ������ ��������
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
    /// �������� ��������
    std::string action_{""};
    /// ������ ����������, �� ������� ����� ������������ ������ �����������, ����� ������������ �� ���������
    std::vector<std::string> src_{std::vector<std::string>()};
    /// ������, �����������, ���� ���������� ����������� ������ ����������� : @see Placeholder ��� �� ������� ���������
    std::string dst_{""};
    /// ���������, ����������� �������� ���������� � �� ��������
    std::map<std::string, std::string> settings_{std::map<std::string, std::string>()};
};


#endif 
