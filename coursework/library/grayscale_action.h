#ifndef GREYSCALEACTION_H
#define GREYSCALEACTION_H

#include "base_action.h"

/**
    @brief Операция изменения цвета изображений на черно-белый
    @ingroup actions_module

    @details
    Приём :  массив Placeholder\n
    Отправка : Placeholder\n
    Параметры :  alpha_channel bool (надо ли учитывать альфа-канал при обработке)

    @see Placeholder
*/
class GrayscaleAction : public BaseAction {
public:
    GrayscaleAction();

    int execute(PlaceholderStorage* placeholder_storage,
                std::vector<std::string> src,
                std::map<std::string, std::string>& settings,
                std::string dst);
private:
};


#endif  // GREYSCALEACTION_H
