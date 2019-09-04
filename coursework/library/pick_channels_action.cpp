#include "pick_channels_action.h"

using namespace std;
using namespace cv;

PickChannelsAction::PickChannelsAction() : BaseAction() {
    name_ = "pick_channels";
    addSetting("red", "true");
    addSetting("green", "true");
    addSetting("blue", "true");
    addSetting("alpha", "true");
}

int PickChannelsAction::execute(PlaceholderStorage* placeholder_storage,
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

    bool red_channel;
    istringstream(action_settings["red"]) >> std::boolalpha >> red_channel;
    bool green_channel;
    istringstream(action_settings["green"]) >> std::boolalpha >> green_channel;
    bool blue_channel;
    istringstream(action_settings["blue"]) >> std::boolalpha >> blue_channel;
    bool alpha_channel;
    istringstream(action_settings["alpha"]) >> std::boolalpha >> alpha_channel;

    for (map<string, Mat>::iterator it = image_set.begin(); it != image_set.end(); ++it) {
        Mat image = it->second;
        Mat channels[4];
        split(image, channels);

        Mat red = channels[2];
        Mat green = channels[1];
        Mat blue = channels[0];
        Mat alpha = channels[3];

        if (!red_channel) {
            channels[2] = Mat::zeros(image.rows, image.cols, CV_8UC1);
        }
        if (!green_channel) {
            channels[1] = Mat::zeros(image.rows, image.cols, CV_8UC1);
        }
        if (!blue_channel) {
            channels[0] = Mat::zeros(image.rows, image.cols, CV_8UC1);
        }
        if (!alpha_channel) {
            channels[3].setTo(255);
        }

        merge(channels, image.channels(), it->second);
    }


    if (dst != "") {
        placeholder_storage->createPlaceholder(dst, image_set);
    }

    return 0;
}
