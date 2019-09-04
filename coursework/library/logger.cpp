#include "logger.h"

using namespace std;

void Logger::setPath(string log_file_path) {
    log_file_path_ = log_file_path;
}

void Logger::writeInFile(string const& s) {
    ofstream log_file;
    log_file.open(log_file_path_, ios::out | ios::app);
    log_file << s;
    log_file.close();
}

Logger* Logger::p_instance_ = 0;

Logger* Logger::getInstance() {
    if (!p_instance_)
        p_instance_ = new Logger();
    return p_instance_;
}