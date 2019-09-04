#include "base_action.h"
#include "placeholder_storage.h"

using namespace std;
using namespace cv;

BaseAction::BaseAction() {
    name_ = "";
    default_settings_ = {};
}

BaseAction::~BaseAction() {
    default_settings_.clear();
}

int BaseAction::execute(PlaceholderStorage* placeholder_storage, 
                        vector<string> src,
                        map<std::string, string>& settings,
                        string dst) {
    return 0;
}

string BaseAction::getName() {
    return name_;
}

void BaseAction::addSetting(string key, string default_value) {
    default_settings_.insert(pair<string, string>(key, default_value));
}

map<string, Mat> BaseAction::submitSrc(PlaceholderStorage* placeholder_storage, 
                                   vector<string>& src, 
                                   char constraints) {
    // TAKE CARE ABOUT CONSTRAINTS
    if (!(constraints & Constraint::SRC_PATH)) {
        for (int i = src.size()-1; i >= 0; i--) {
            if (!placeholder_storage->isPlaceholderFormat(src.at(i))) {
                src.erase(src.begin() + i);
            }
        }
    }
    if(!(constraints & Constraint::SRC_PLACEHOLDER)) {
        for (int i = src.size() - 1; i >= 0; i--) {
            if (placeholder_storage->isPlaceholderFormat(src.at(i))) {
                src.erase(src.begin() + i);
            }
        }
    }
    map<string, Mat>& imageSet = placeholder_storage->srcToImageSet(src);
    if (imageSet.empty()) {
        log << "Warning : manipulating empty image set " << "\n";
    }
    return imageSet;
}

string BaseAction::submitDst(PlaceholderStorage* placeholder_storage, string dst, char constraints) {
    if (!(constraints & Constraint::DST_PATH)) {
        if (!placeholder_storage->isPlaceholderFormat(dst)) {
            return "";
        }
    }
    if (!(constraints & Constraint::DST_PLACEHOLDER)) {
        if (placeholder_storage->isPlaceholderFormat(dst)) {
            return "";
        }
    }
    return dst;
}

map<string, string> BaseAction::submitSettings(map<string, string>& settings) {
    map<string, string> temp_settings(default_settings_);
    for (map<string, string>::iterator it = settings.begin(); it != settings.end(); ++it) {
        if (default_settings_.find(it->first) != default_settings_.end()) {
            temp_settings.at(it->first) = it->second;
        }
        else {
            throw logic_error("Error: try to submit non-existing setting -> "+it->first);
        }
    }
    return temp_settings;
}