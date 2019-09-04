#ifndef ROTATEACTION_H
#define ROTATEACTION_H

#include "base_action.h"

/**
    @brief Операция поворота изображений по или против часовой стрелки
    @ingroup actions_module

    @details
    Приём :  массив Placeholder\n
    Отправка : Placeholder\n
    Параметры :  clockwise bool (по или против часовой стрелки)

    @see Placeholder
*/
class RotateAction : public BaseAction {
public:
    RotateAction();

    int execute(PlaceholderStorage* placeholder_storage,
                std::vector<std::string> src,
                std::map<std::string, std::string>& settings,
                std::string dst);
private:
};


#endif  // ROTATEACTION_H
