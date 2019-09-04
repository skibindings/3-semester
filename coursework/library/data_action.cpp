#include "data_action.h"

using namespace std;
using namespace cv;

DataAction::DataAction() : BaseAction() {
    name_ = "data";
    addSetting("max_entries", "100");
    addSetting("allow_png", "true");
    addSetting("allow_jpg", "true");
}

int DataAction::execute(PlaceholderStorage* placeholder_storage,
                        vector<string> src,
                        map<string, string>& settings,
                        string dst) {

    map<string, string> action_settings;
    try {
        action_settings = submitSettings(settings);
    }
    catch (const logic_error& e) {
        log << e.what() << "\n";
        return EXIT_FAILURE;
    }

    map<string, Mat> image_set;
    try {
        image_set = submitSrc(placeholder_storage, src, Constraint::SRC_PATH);
    }
    catch (const logic_error& e) {
        log << e.what() << "\n";
        return EXIT_FAILURE;
    }

    dst = submitDst(placeholder_storage, dst, Constraint::DST_PLACEHOLDER);

    bool allow_png;
    istringstream(action_settings["allow_png"]) >> std::boolalpha >> allow_png;

    bool allow_jpg;
    istringstream(action_settings["allow_jpg"]) >> std::boolalpha >> allow_jpg;

    map<string, Mat>::iterator it = image_set.begin();

    while (it != image_set.end()) {
        string file_name = it->first;

        const size_t last_dot_idx = file_name.find_last_of(".");
        const string const_extension = file_name.substr(last_dot_idx);

        bool eraseElement = false;

        if (!allow_png) {
            if (const_extension.compare(".png") == 0) {
                eraseElement = true;
            }
        }
        if (!allow_jpg && !eraseElement) {
            if (const_extension.compare(".jpg") == 0 || const_extension.compare(".jpeg") == 0) {
                eraseElement = true;
            }
        }

        if (!eraseElement)
            ++it;
        else
            it = image_set.erase(it);
    }

    int max_entries = stoi(action_settings["max_entries"]);
    if (image_set.size() > max_entries) {
        while (image_set.size() != max_entries) {
            image_set.erase(prev(image_set.end()));
        }
    }

    if (dst != "") {
        placeholder_storage->createPlaceholder(dst, image_set);
    }

    return 0;
}
