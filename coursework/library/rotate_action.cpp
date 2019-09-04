#include "rotate_action.h"

using namespace std;
using namespace cv;

RotateAction::RotateAction() : BaseAction() {
    name_ = "rotate";
    addSetting("clockwise", "true");
    addSetting("angle", "0");
}

int RotateAction::execute(PlaceholderStorage* placeholder_storage,
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

    bool clockwise;
    istringstream(action_settings["clockwise"]) >> std::boolalpha >> clockwise;
    int flag = clockwise ? -1 : 1;

    int angle = stoi(action_settings["angle"]) * flag;

    for (map<string, Mat>::iterator it = image_set.begin(); it != image_set.end(); ++it) {
        Point2f center((it->second.cols - 1) / 2.0, (it->second.rows - 1) / 2.0);
        Mat rot = getRotationMatrix2D(center, angle, 1.0);
        Rect2f bbox = RotatedRect(Point2f(), it->second.size(), angle).boundingRect2f();

        rot.at<double>(0, 2) += bbox.width / 2.0 - it->second.cols / 2.0;
        rot.at<double>(1, 2) += bbox.height / 2.0 - it->second.rows / 2.0;

        warpAffine(it->second, it->second, rot, bbox.size());
    }

    if (dst != "") {
        placeholder_storage->createPlaceholder(dst, image_set);
    }

    return 0;
}
