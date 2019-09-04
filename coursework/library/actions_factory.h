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
    @brief �����, ���������� ��� �������������� ���������� �������� BaseAction, ������� ����� ����������� ��� �������������
    @see BaseAction
    
    @details ����������� ��������� ������������������ �������� �� ����� ������������ � ��������
*/

class ActionsFactory {
public:
    ActionsFactory();
    ~ActionsFactory();

    /**
    @brief ����������� ��������� ���������� �� ������� @Layer � �������� 
    @see Layer
    @param layer ���������, �������� ������ �� �������� � ��������� ����
    @return ���������� ���������� �������
    */
    int processLayer(Layer* layer);

private:
    void addAction(BaseAction* action);
    std::map<std::string, BaseAction*> actionsLibrary_;
    PlaceholderStorage* placeholder_storage_;


    Logger log{ *Logger::getInstance() };
};


#endif 
