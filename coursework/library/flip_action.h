#ifndef FLIPACTION_H
#define FLIPACTION_H

#include "base_action.h"

/**
    @brief ќпераци€ зеркального отражени€ изображений
    @ingroup actions_module

    @details
    ѕриЄм :  массив Placeholder\n
    ќтправка : Placeholder\n
    ѕараметры :  type string (УverticallyФ, УhorizontallyФ)

    @see Placeholder
*/
class FlipAction : public BaseAction {
public:
    FlipAction();

    int execute(PlaceholderStorage* placeholder_storage,
                std::vector<std::string> src,
                std::map<std::string, std::string>& settings,
                std::string dst);
private:
};


#endif  // FLIPACTION_H
