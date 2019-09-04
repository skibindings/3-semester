#ifndef DATAACTION_H
#define DATAACTION_H

#include "base_action.h"

/**
    @brief �������� �������� ����������� �� ������� ������
    @ingroup actions_module

    @details
    ���� :  ������ ����� � ��������� ��� ��������� ������\n
    �������� : Placeholder\n
    ��������� : max_entries int (������������ ���������� �����������, ������� ����� �������� � placeholder)

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
