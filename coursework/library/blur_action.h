#ifndef BLURACTION_H
#define BLURACTION_H

#include "base_action.h"

/**
    @brief �������� �������� �����������
    @ingroup actions_module

    @details
    ���� :  ������ Placeholder\n
    �������� : Placeholder\n
    ��������� :  filter string (�homogeneous�, �gaussian�, �median�, �bilateral�) ;\n
    kernel_length int (������ ���� �������� 1-31)

    @see Placeholder
*/
class BlurAction : public BaseAction {
public:
    BlurAction();

    int execute(PlaceholderStorage* placeholder_storage,
                std::vector<std::string> src,
                std::map<std::string, std::string>& settings,
                std::string dst);
private:
    const int kMaxKernelLength{ 31 };
};


#endif  // BLURACTION_H
