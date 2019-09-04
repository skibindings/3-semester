#include "placeholder.h"

using namespace std;
using namespace cv;

Placeholder::Placeholder(std::string name, std::map<string, Mat>& image_set) :
    name_(name), image_set_(image_set)
{
}

Placeholder::~Placeholder() {
    for (map<string, Mat>::iterator it = image_set_.begin(); it != image_set_.end(); ++it) {
        (it->second).release();
    }
    image_set_.clear();
}

void Placeholder::concatenateImageSetTo(map<string, Mat>& other) {
    for (map<string, Mat>::iterator it = image_set_.begin(); it != image_set_.end(); ++it) {
        Mat image = (it->second).clone();
        const string const_name = it->first;

        const size_t last_dot_idx = const_name.find_last_of(".");
        const string const_name_no_extension = it->first.substr(0, last_dot_idx);
        const string const_extension = it->first.substr(last_dot_idx);

        string name = it->first;
        int counter = 1;
        while (other.find(name) != other.end()) {
            name = const_name_no_extension + to_string(counter) + const_extension;
            counter++;
        }
        other.insert(pair<string, Mat>(name, image));
    }
}
