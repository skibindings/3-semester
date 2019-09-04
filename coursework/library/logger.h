#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <sstream>
#include <fstream> 
/**
    @brief Класс выводит ошибки и предупреждения, возникшие в результате работы программы в отдельный .txt файл
*/
class Logger {
public:
    Logger() = default;

    /**
    @param log_file_path Путь к .txt файлу, в который будут отправляться log сообщения
    */
    void setPath(std::string log_file_path);
    /**
    @param s Строка, которая будет записываться в log файл
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
