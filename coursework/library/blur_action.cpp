#include "blur_action.h"

using namespace std;
using namespace cv;

BlurAction::BlurAction() : BaseAction() {
    name_ = "blur";
    addSetting("kernel_length", "15");
    addSetting("filter", "homogeneous");
}

int BlurAction::execute(PlaceholderStorage* placeholder_storage,
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

    int kernel_length = stoi(action_settings["kernel_length"]);
    if (kernel_length < 1) {
        kernel_length = 1;
    } else {
        kernel_length = min(kernel_length, kMaxKernelLength);
    }

    int flag;
    string filter = action_settings["filter"];
    if (filter.compare("homogeneous")) {
        flag = 0;
    }
    else if (filter.compare("gaussian")) {
        flag = 1;
    }
    else if (filter.compare("median")) {
        flag = 2;
    }
    else if (filter.compare("bilateral")) {
        flag = 3;
    }

    switch (flag) {
    case 0 :
        for (map<string, Mat>::iterator it = image_set.begin(); it != image_set.end(); ++it) {
            for (int i = 1; i < kernel_length; i = i + 2) {
                blur(it->second, it->second, Size(i, i), Point(-1, -1));
            }
        }
        break;
    case 1:
        for (map<string, Mat>::iterator it = image_set.begin(); it != image_set.end(); ++it) {
            for (int i = 1; i < kernel_length; i = i + 2) {
                GaussianBlur(it->second, it->second, Size(i, i), 0, 0);
            }
        }
        break;
    case 2:
        for (map<string, Mat>::iterator it = image_set.begin(); it != image_set.end(); ++it) {
            for (int i = 1; i < kernel_length; i = i + 2) {
                medianBlur(it->second, it->second, i);
            }
        }
        break;
    case 3:
        for (map<string, Mat>::iterator it = image_set.begin(); it != image_set.end(); ++it) {
            for (int i = 1; i < kernel_length; i = i + 2) {
                bilateralFilter(it->second, it->second, i, i * 2, i / 2);
            }
        }
        break;
    }

    if (dst != "") {
        placeholder_storage->createPlaceholder(dst, image_set);
    }

    return 0;
}
