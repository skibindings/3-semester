#include "actions_factory.h"

using namespace std;

ActionsFactory::ActionsFactory() {
    actionsLibrary_ = map<string, BaseAction*>();

    addAction(new DataAction());
    addAction(new SaveAction());
    addAction(new GrayscaleAction());
    addAction(new PickChannelsAction());
    addAction(new FlipAction());
    addAction(new RotateAction());
    addAction(new BlurAction());

    placeholder_storage_ = new PlaceholderStorage();
}

ActionsFactory::~ActionsFactory() {
    for (map<string, BaseAction*>::iterator it = actionsLibrary_.begin(); it != actionsLibrary_.end(); ++it) {
        delete it->second;
    }
    actionsLibrary_.clear();

    delete placeholder_storage_;
}

void ActionsFactory::addAction(BaseAction* action) {
    actionsLibrary_.insert(pair<string,BaseAction*>(action->getName(),action));
}

int ActionsFactory::processLayer(Layer* layer) {
    if (actionsLibrary_.find(layer->getAction()) != actionsLibrary_.end()) {
        BaseAction* action = actionsLibrary_.at(layer->getAction());

        int error_status = action->execute(placeholder_storage_, layer->getSrc(), layer->getSettings(), layer->getDst());
        if (error_status == EXIT_FAILURE) {
            return EXIT_FAILURE;
        }
    } else {
        // NON-EXISTING ACTION
        log << "Error : try to process non-existing action -> " << layer->getAction() << "\n";
        return EXIT_FAILURE;
    }
    return 0;
}