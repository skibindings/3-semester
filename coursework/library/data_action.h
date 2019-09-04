#ifndef DATAACTION_H
#define DATAACTION_H

#include "base_action.h"

/**
    @brief Операция загрузки изображений из внешней памяти
    @ingroup actions_module

    @details
    Приём :  массив путей к каталогам или отдельным файлам\n
    Отправка : Placeholder\n
    Параметры : max_entries int (максимальное количество изображений, которые будут помещены в placeholder)

    @see Placeholder
*/
class DataAction : public BaseAction {
public:
    DataAction();

    int execute(PlaceholderStorage* placeholder_storage,
                std::vector<std::string> src,
                std::map<std::string, std::string>& settings,
                std::string dst);
private:
};


#endif 
