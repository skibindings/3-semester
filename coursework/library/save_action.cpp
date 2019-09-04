#include "save_action.h"

using namespace std;
using namespace cv;

SaveAction::SaveAction() : BaseAction() {
    name_ = "save";
}

int SaveAction::execute(PlaceholderStorage* placeholder_storage,
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

    // if dst directory doesn't exist 
    dst = submitDst(placeholder_storage, dst, Constraint::DST_PATH);
    if (!dst.empty()) {
        _mkdir(dst.c_str());
        if (dst.back() != '/') {
            dst = dst + "/";
        }
    }
    for (map<string, Mat>::iterator it = image_set.begin(); it != image_set.end(); ++it) {
        string save_path = dst;
        Mat save_image = it->second;
        save_path = dst+it->first;
        imwrite(save_path, save_image);
    }

    return 0;
}
