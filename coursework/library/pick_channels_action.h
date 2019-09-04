#ifndef PICK_CHANNELS_ACTION_H
#define PICK_CHANNELS_ACTION_H

#include "base_action.h"

/**
    @brief �������� ������� ��������� �������� ������� ����������� (red/green/blue)
    @ingroup actions_module

    @details
    ���� :  ������ Placeholder\n
    �������� : Placeholder\n
    ��������� :  \n
    red bool (��������� ����� �������� �����) ; \n
    green bool (��������� ����� �������� �����) ; \n
    blue bool (��������� ����� ������ �����) ; \n
    alpha bool (��������� �����-�����)

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
