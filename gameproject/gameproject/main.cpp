#include <iostream>
#include "GameController.h"
#include "StartUp.h"


int main() {
    
    StartUp();

    
    GameController controller(1);
    controller.run();

    std::cout << "���α׷��� ���� ����Ǿ����ϴ�.\n";
    return 0;
}