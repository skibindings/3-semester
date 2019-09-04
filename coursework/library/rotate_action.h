#ifndef ROTATEACTION_H
#define ROTATEACTION_H

#include "base_action.h"

/**
    @brief �������� �������� ����������� �� ��� ������ ������� �������
    @ingroup actions_module

    @details
    ���� :  ������ Placeholder\n
    �������� : Placeholder\n
    ��������� :  clockwise bool (�� ��� ������ ������� �������)

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
