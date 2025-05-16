#include "Ending.h"

void ending_rog() {
    int day = 3; // 예시값, 원하는 값으로 변경 가능

    if (day == 1) {
        Ending::display("안녕 1");
    }
    else if (day == 2) {
        Ending::display("안녕 2");
    }
    else if (day == 3) {
        Ending::display("안녕 3");
    }
    else if (day == 4) {
        Ending::display("안녕 4");
    }
    else if (day == 5) {
        Ending::display("안녕 5");
    }
    else {
        Ending::display("해당하는 메시지가 없습니다");
    }
}