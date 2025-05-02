#pragma once
#include "stats.h"
#include <iostream>
#include <string>

using namespace std;

class next_day {
public:
    void print_day_result() {
        int dDay = 60 - progress;

        int healthChange = -15;
        int progressChange = +15;
        int moneyChange = 70000;

        string comment1 = "�˹ٸ� �ϴٰ� �մ��� ���Ƽ� ����� �ʾ���...";
        string comment2 = "���ʽ��� �޾����� �ʹ� �����... \n\nGithub���� ������ �߰��ߴ�!\n�ڵ带 ������ �� �־ ������ �����߾�.";

        int healthBar = health / 5;
        int progressBar = progress / 5;

        cout << "========================================================\n";
        cout << "                     ��� ���\n";
        cout << "========================================================\n\n";

        cout << "������ �ϰ�\n";
        cout << "  ����: �˹�\n";
        cout << "  ����: �����ϱ�\n";

        cout << "\n--------------------------------------------------------\n";
        cout << " ���� ��ȭ ���:\n\n";

        cout << "  ü��     : [";
        for (int i = 0; i < healthBar; i++) cout << "|";
        for (int i = healthBar; i < 10; i++) cout << " ";
        cout << "] " << health << "%  (" << (healthChange > 0 ? "+" : "") << healthChange << "%)\n";

        cout << "  �ϼ���   : [";
        for (int i = 0; i < progressBar; i++) cout << "|";
        for (int i = progressBar; i < 20; i++) cout << " ";
        cout << "] " << progress << "%  (" << (progressChange > 0 ? "+" : "") << progressChange << "%)\n";

        cout << " ��     : " << moneyChange << " ����\n";

        cout << "\n--------------------------------------------------------\n";
        cout << " �ڸ�Ʈ:\n";
        cout << comment1 << endl;
        cout << comment2 << endl;

        cout << "\n========================================================\n";
        cout << "[Enter] ���� ���� �Ѿ��\n";
        cout << "========================================================\n";
    }
};