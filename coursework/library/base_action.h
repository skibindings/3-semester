#ifndef BASEACTION_H
#define BASEACTION_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>

#include "logger.h"
#include "placeholder_storage.h"

/** @defgroup actions_module ��������� ����������� */

/**
    @brief ������������ ����� ��������� ����������� ��� �������������
    @ingroup actions_module
*/

class BaseAction {
public:
    BaseAction();
    ~BaseAction();


    /**
        @brief �������� ������ �����������, �����, ���������������, ���������� ��������� �������� ����������� 
        @param placeholder_storage �������� ��������� @see Placeholder , ����������� ��� �������������� � ��������� �����������, �������� ����������� � ����������� ������
        @param src ������ �����, �����������, ����� ����������� ������ ���� ����������� �����������
        @param settings ���������, ����������� �������� ���������� � �� ��������
        @param dst C�����, �����������, ���� ����� ���������� ���������������� �����������
        @return ���������� ���������� ������� 
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

    /// ����� ��������� ���������� �� src � dst ��������
    enum Constraint : char {
        NONE = 0, ///< ���������� ���
        /**
        < � �������� ��������� ����������� ��������� ������ Placeholder
        @see Placeholder
        */
        SRC_PLACEHOLDER = 1 << 0,
        SRC_PATH = 1 << 1, ///< � �������� ��������� ����������� ��������� ������ ���� � ��������� � ������ �� ������� ������
        /**
        < � �������� �������� ������������� ������� ����������� �������� ������ Placeholder
        @see Placeholder
        */
        DST_PLACEHOLDER = 1 << 2,
        DST_PATH = 1 << 3, ///< � �������� �������� ������������� ������� ����������� �������� ������ ������ ���� � �������� �� ������� ������
        DEDAULT = SRC_PLACEHOLDER|SRC_PATH|DST_PLACEHOLDER|DST_PATH ///< ������������ ����������
    };
};


#endif 
