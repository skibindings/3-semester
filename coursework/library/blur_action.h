#ifndef BLURACTION_H
#define BLURACTION_H

#include "base_action.h"

/**
    @brief ќпераци€ размыти€ изображений
    @ingroup actions_module

    @details
    ѕриЄм :  массив Placeholder\n
    ќтправка : Placeholder\n
    ѕараметры :  filter string (УhomogeneousФ, УgaussianФ, УmedianФ, УbilateralФ) ;\n
    kernel_length int (размер €дра размыти€ 1-31)

    @see Placeholder
*/
class BlurAction : public BaseAction {
public:
    BlurAction();

    int execute(PlaceholderStorage* placeholder_storage,
                std::vector<std::string> src,
                std::map<std::string, std::string>& settings,
                std::string dst);
private:
    const int kMaxKernelLength{ 31 };
};


#endif  // BLURACTION_H
