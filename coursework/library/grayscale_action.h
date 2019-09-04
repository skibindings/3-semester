#ifndef GREYSCALEACTION_H
#define GREYSCALEACTION_H

#include "base_action.h"

/**
    @brief �������� ��������� ����� ����������� �� �����-�����
    @ingroup actions_module

    @details
    ���� :  ������ Placeholder\n
    �������� : Placeholder\n
    ��������� :  alpha_channel bool (���� �� ��������� �����-����� ��� ���������)

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
