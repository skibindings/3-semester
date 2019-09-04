#ifndef PICK_CHANNELS_ACTION_H
#define PICK_CHANNELS_ACTION_H

#include "base_action.h"

/**
    @brief Операция выборки отдельных цветовых каналов изображений (red/green/blue)
    @ingroup actions_module

    @details
    Приём :  массив Placeholder\n
    Отправка : Placeholder\n
    Параметры :  \n
    red bool (сохранить канал красного цвета) ; \n
    green bool (сохранить канал зеленого цвета) ; \n
    blue bool (сохранить канал синего цвета) ; \n
    alpha bool (сохранить альфа-канал)

    @see Placeholder
*/
class PickChannelsAction : public BaseAction {
public:
    PickChannelsAction();

    int execute(PlaceholderStorage* placeholder_storage,
                std::vector<std::string> src,
                std::map<std::string, std::string>& settings,
                std::string dst);
private:
};


#endif  // GREYSCALEACTION_H
