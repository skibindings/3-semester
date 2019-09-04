#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <sstream>
#include <fstream> 
/**
    @brief ����� ������� ������ � ��������������, ��������� � ���������� ������ ��������� � ��������� .txt ����
*/
class Logger {
public:
    Logger() = default;

    /**
    @param log_file_path ���� � .txt �����, � ������� ����� ������������ log ���������
    */
    void setPath(std::string log_file_path);
    /**
    @param s ������, ������� ����� ������������ � log ����
    */
    void writeInFile(std::string const& s);

    /**
    @private
    */
    static Logger* getInstance();

private:
    std::string log_file_path_{""};
    static Logger* p_instance_;
};

template<typename T>
Logger& operator << (Logger& out, T val) {
    std::stringstream ss;
    ss << val;
    out.writeInFile(ss.str());
    return out;
}

#endif  // LOGGER_H
