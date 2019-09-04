#include "layer.h"

using namespace std;
using namespace nlohmann;

Layer::Layer(const json& j) {
    action_ = j["action"].get<string>();
    src_ = j["src"].get<vector<string>>();
    dst_ = j["dst"].get<string>();
    settings_ = j["settings"].get<map<string, string>>();
}

Layer::~Layer() {
    src_.clear();
    src_.shrink_to_fit();

    settings_.clear();
}

string Layer::getAction() {
    return action_;
}

vector<string> Layer::getSrc() {
    return src_;
}

string Layer::getDst() {
    return dst_;
}

map<string, string> Layer::getSettings() {
    return settings_;
}

void Layer::debugPrint() {
    cout << action_ << endl;
    for (int i = 0; i < src_.size(); i++) {
        cout << src_[i] << endl;
    }
    cout << dst_ << endl;
    for (map<string, string>::iterator it = settings_.begin(); it != settings_.end(); ++it)
        cout << it->first << " => " << it->second << '\n';
}