#include "placeholder_storage.h"

using namespace std;
using namespace cv;

PlaceholderStorage::PlaceholderStorage() {
    placeholders_ = map<string, Placeholder*>();
}

PlaceholderStorage::~PlaceholderStorage() {
    for (map<string, Placeholder*>::iterator it = placeholders_.begin(); it != placeholders_.end(); ++it) {
        delete it->second;
    }
    placeholders_.clear();
}

map<string, Mat> PlaceholderStorage::srcToImageSet(vector<string>& src) {

    map<string, Mat> new_image_set = map<string, Mat>();

    for (int i = 0; i < src.size(); i++) {
        string one_src = src[i];

        // looking for existing placeholders
        if (isPlaceholderFormat(one_src)) {
            if (placeholderExists(one_src)) {
                // cloning their image sets
                placeholders_.at(one_src)->concatenateImageSetTo(new_image_set); 
            }
            else {
                throw logic_error("Error: try to use non-existing placeholder -> " + one_src);
            }
        }
        // loading image sets from external storage
        else {
            struct stat s;
            struct stat s_inner;

            string substring = one_src.substr(one_src.length() - 2);
            bool require_directory = false;
            if (substring.compare("/*") == 0 ||
                substring.compare("\*") == 0) {
                one_src = one_src.substr(0, one_src.length() - 2);
                require_directory = true;
            }

            if (stat(one_src.c_str(), &s) == 0) {

                //it's a directory
                if (s.st_mode & S_IFDIR) {
                    DIR *dir;
                    struct dirent *ent;
                    if ((dir = opendir(one_src.c_str())) != NULL) {
                        // look for all files in directory
                        while ((ent = readdir(dir)) != NULL) {
                            bool wrong_name = false;
                            string file_name = ent->d_name;
                            if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, "..")) {
                                wrong_name = true;
                            }

                            // name should be correct 
                            if (!wrong_name) {
                                // make full path to image
                                string file_path;
                                if (one_src.back() == '/') {
                                    file_path = one_src + ent->d_name;
                                }
                                else {
                                    file_path = one_src + '/' + ent->d_name;
                                }
                                // pick only files
                                if (stat(file_path.c_str(), &s_inner) == 0) {
                                    cout << file_path << endl;
                                    if (s_inner.st_mode & S_IFREG) {
                                        // Read the file
                                        Mat image = imread(file_path.c_str(), IMREAD_UNCHANGED);
                                        // Check for invalid input
                                        if (image.empty()) {
                                            log << "Warning : could not open or find the image -> " << file_path << "\n";
                                        }
                                        else {
                                            // Add loaded image to image set
                                            const string const_file_name = file_name;

                                            const size_t last_dot_idx = const_file_name.find_last_of(".");
                                            const string const_file_name_no_extension = file_name.substr(0, last_dot_idx);
                                            const string const_extension = file_name.substr(last_dot_idx);

                                            int counter = 1;
                                            while (new_image_set.find(file_name) != new_image_set.end()) {
                                                file_name = const_file_name_no_extension + to_string(counter) + const_extension;
                                                counter++;
                                            }
                                            new_image_set.insert(pair<string, Mat>(file_name, image));
                                        }
                                    }
                                }
                                else {
                                    log << "Warning : could not open path -> " << file_path << "\n";
                                }
                            }
                        }
                        closedir(dir);
                    }
                    else {
                        // error
                    }
                }
                //it's a file
                else if (s.st_mode & S_IFREG && !require_directory) {
                    // Read the file
                    Mat image = imread(one_src.c_str(), IMREAD_UNCHANGED);
                    // Check for invalid input
                    if (image.empty()) {
                        log << "Warning : could not open or find the image -> " << one_src << "\n";
                    }
                    else {
                        // Add loaded image to image set

                        // get file_name with extension 
                        string file_name = one_src;
                        const size_t last_slash_idx = file_name.find_last_of("\\/");
                        if (std::string::npos != last_slash_idx) {
                            file_name.erase(0, last_slash_idx + 1);
                        }

                        // file names should not repeat in set 
                        const string const_file_name = file_name;

                        const size_t last_dot_idx = const_file_name.find_last_of(".");
                        const string const_name_no_extension = file_name.substr(0, last_dot_idx);
                        const string const_extension = file_name.substr(last_dot_idx);

                        int counter = 1;
                        while (new_image_set.find(file_name) != new_image_set.end()) {
                            file_name = const_name_no_extension + to_string(counter) + const_extension;
                            counter++;
                        }
                        new_image_set.insert(pair<string, Mat>(file_name, image));
                    }
                }
                //something else
                else {
                    
                }
            }
            else {
                log << "Warning : could not open path -> " << one_src << "\n";
            }
        }
    }
    return new_image_set;
}

Placeholder* PlaceholderStorage::createPlaceholder(string name, map<std::string, cv::Mat> image_set) {
    if (placeholderExists(name)) {
        log << "Warning : try to create duplicate of existing placeholder -> " << name << "\n";
        log << "Warning : old placeholder was replaced with new one" << "\n";
        placeholders_.erase(name);
    }
    Placeholder* new_placeholder = new Placeholder(name, image_set);
    placeholders_.insert(pair<string, Placeholder*>(name, new_placeholder));

    return new_placeholder;
}

bool PlaceholderStorage::isPlaceholderFormat(string str) {
    if (str.empty())
        return false;

    return (str.front() == '$');
}

bool PlaceholderStorage::placeholderExists(string name) {
    return (placeholders_.find(name) != placeholders_.end());
}

