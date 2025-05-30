#pragma once
#include "stats.h"
#include <iostream>
#include <string>

using namespace std;

class next_day {
public:
    string convertPlan(const string& plan) {
        if (plan == "1") return "�˹��ϱ�";
        if (plan == "2") return "�����";
        if (plan == "3") return "�����ϱ�";
        if (plan == "4") return "����";
        return "����";
    }

    void print_day_result(int currentDay, string morningPlan, string afternoonPlan, int money, int healthChange, int progressChange, int teamworkChange, int moneyChange) {
        system("cls");

        int dDay = 60 - currentDay;
        int healthBar = health / 5;
        int progressBar = progress / 5;
        int teamworkBar = teamwork / 5;

        cout << "========================================================\n";
        cout << "                    [Day " << currentDay << "  D-" << dDay << "]                      \n";
        cout << "========================================================\n\n";

        cout << "������ �ϰ� ���:\n";
        cout << "  ����: " << convertPlan(morningPlan) << "\n";
        cout << "  ����: " << convertPlan(afternoonPlan) << "\n";

        cout << "\n--------------------------------------------------------\n";
        cout << " ���� ��ȭ ���:\n\n";

        cout << "  ��       : " << money << "�� (" << (moneyChange > 0 ? "+" : "") << moneyChange << ")\n";

        cout << "  ü��     : [";
        for (int i = 0; i < healthBar; i++) cout << "|";
        for (int i = healthBar; i < 10; i++) cout << " ";
        cout << "] " << health << "% (" << (healthChange > 0 ? "+" : "") << healthChange << "%)\n";

        cout << "  ���൵   : [";
        for (int i = 0; i < progressBar; i++) cout << "|";
        for (int i = progressBar; i < 20; i++) cout << " ";
        cout << "] " << progress << "% (" << (progressChange > 0 ? "+" : "") << progressChange << "%)\n";

        cout << "  ���µ�   : [";
        for (int i = 0; i < teamworkBar; i++) cout << "|";
        for (int i = teamworkBar; i < 20; i++) cout << " ";
        cout << "] " << teamwork << "% (" << (teamworkChange > 0 ? "+" : "") << teamworkChange << "%)\n";

        cout << "\n========================================================\n";
        //cout << "[Enter]�� ���� ���� ���� �Ѿ��...";
    }
};