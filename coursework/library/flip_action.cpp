#include "flip_action.h"

using namespace std;
using namespace cv;

FlipAction::FlipAction() : BaseAction() {
    name_ = "flip";
    addSetting("type", "horizontally");
}

int FlipAction::execute(PlaceholderStorage* placeholder_storage,
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
        image_set = submitSrc(placeholder_storage, src, Constraint::SRC_PLACEHOLDER);
    }
    catch (const logic_error& e) {
        log << e.what() << "\n";
        return EXIT_FAILURE;
    }

    dst = submitDst(placeholder_storage, dst, Constraint::DST_PLACEHOLDER);

    string type;
    int flag = 0;
    type = action_settings["type"];
    if (type.compare("horizontally") == 0) {
        flag = 1;
    }
    if (type.compare("vertically") == 0) {
        flag = 0;
    }

    for (map<string, Mat>::iterator it = image_set.begin(); it != image_set.end(); ++it) {
        flip(it->second, it->second, flag);
    }

    if (dst != "") {
        placeholder_storage->createPlaceholder(dst, image_set);
    }

    return 0;
}
