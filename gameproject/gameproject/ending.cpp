#include "Ending.h"

void ending_rog() {
    int day = 3; // ���ð�, ���ϴ� ������ ���� ����

    if (day == 1) {
        Ending::display("�ȳ� 1");
    }
    else if (day == 2) {
        Ending::display("�ȳ� 2");
    }
    else if (day == 3) {
        Ending::display("�ȳ� 3");
    }
    else if (day == 4) {
        Ending::display("�ȳ� 4");
    }
    else if (day == 5) {
        Ending::display("�ȳ� 5");
    }
    else {
        Ending::display("�ش��ϴ� �޽����� �����ϴ�");
    }
}