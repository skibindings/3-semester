#include "grayscale_action.h"

using namespace std;
using namespace cv;

GrayscaleAction::GrayscaleAction() : BaseAction() {
    name_ = "gray";
    addSetting("alpha_channel", "false");
}

int GrayscaleAction::execute(PlaceholderStorage* placeholder_storage,
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

    bool alpha_channel;
    istringstream(action_settings["alpha_channel"]) >> std::boolalpha >> alpha_channel;

    if (alpha_channel) {
        for (map<string, Mat>::iterator it = image_set.begin(); it != image_set.end(); ++it) {
            Mat image = it->second;
            Mat channels[4];
            split(image, channels);
            Mat alpha = channels[3];

            Mat gray_image;

            cvtColor(image, gray_image, COLOR_RGBA2GRAY);
            channels[0] = gray_image;
            channels[1] = gray_image;
            channels[2] = gray_image;
            channels[3] = alpha;
            
            merge(channels, image.channels(), it->second);
        }
    }
    else {
        for (map<string, Mat>::iterator it = image_set.begin(); it != image_set.end(); ++it) {
            cvtColor(it->second, it->second, COLOR_RGBA2GRAY);
        }
    }

    if (dst != "") {
        placeholder_storage->createPlaceholder(dst, image_set);
    }

    return 0;
}
