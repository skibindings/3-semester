#ifndef ACTIONSFACTORY_H
#define ACTIONSFACTORY_H

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <map>
#include "placeholder_storage.h"
#include "layer.h"

#include "base_action.h"
#include "data_action.h"
#include "save_action.h"
#include "grayscale_action.h"
#include "pick_channels_action.h"
#include "flip_action.h"
#include "rotate_action.h"
#include "blur_action.h"


/**
    @brief Класс, содержащий все предусмтренные программой операции BaseAction, которые могут совершаться над изображениями
    @see BaseAction
    
    @details Преобразует считанную последовательность операций из файла конфигурации в действия
*/

class ActionsFactory {
public:
    ActionsFactory();
    ~ActionsFactory();

    /**
    @brief Преобразует строковую информацию из объекта @Layer в действия 
    @see Layer
    @param layer Экземпляр, хранящий данные об операции в строковом виде
    @return Успешность выполнения команды
    */
    int processLayer(Layer* layer);

private:
    void addAction(BaseAction* action);
    std::map<std::string, BaseAction*> actionsLibrary_;
    PlaceholderStorage* placeholder_storage_;


    Logger log{ *Logger::getInstance() };
};


#endif 
