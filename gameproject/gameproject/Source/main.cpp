#include <iostream>
#include "GameController.h"

int main() {
    GameController controller(1);
    controller.run();

    std::cout << "프로그램이 정상 종료되었습니다.\n";
    return 0;
}