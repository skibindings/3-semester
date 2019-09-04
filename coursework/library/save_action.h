#ifndef SAVEACTION_H
#define SAVEACTION_H

#include "base_action.h"
#include <direct.h>

/**
    @brief Операция сохранения изображений во внешнуюю память
    @ingroup actions_module

    @details
    Приём :  массив Placeholder\n
    Отправка : путь к каталогу\n
    Параметры :  —

    @see Placeholder
*/
class SaveAction : public BaseAction {
public:
    SaveAction();

    int execute(PlaceholderStorage* placeholder_storage,
                std::vector<std::string> src,
                std::map<std::string, std::string>& settings,
                std::string dst);
private:
};


#endif  // SAVEACTION_H
