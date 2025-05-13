#pragma once
#include "stats.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class visual_main {
private:
    string morningPlan;
    string afternoonPlan;

public:
    visual_main(int day = 1)
        : morningPlan("__"), afternoonPlan("__") {
        initializeStats();
    }

    void setMorningPlan(int choice) {
        morningPlan = getPlan(choice);
    }

    void setAfternoonPlan(int choice) {
        afternoonPlan = getPlan(choice);
    }

    string getPlan(int choice) {
        switch (choice) {
        case 1: return "�˹��ϱ�";
        case 2: return "�����";
        case 3: return "�����ϱ�";
        case 4: return "����";
        default: return "__";
        }
    }

    void clearScreen() {
        system("cls");
    }

    void printUI(const string& morningChoice, const string& afternoonChoice, int currentDay) {
        clearScreen();

        int dDay = 60 - currentDay;
        int healthBar = health / 5;
        int teamworkBar = teamwork / 5;
        int progressBar = progress / 5;

        cout << "========================================================\n";
        cout << "                    [Day " << currentDay << "  D-" << dDay << "]                      \n";
        cout << "========================================================\n\n";

        cout << "���� �� �ϰ��� �����ϼ���.\n";
        cout << "  [1] �˹��ϱ�\n";
        cout << "  [2] �����\n";
        cout << "  [3] �����ϱ�\n";
        cout << "  [4] ����\n";

        cout << "\n--------------------------------------------------------\n";
        cout << "Today's Plan\n";
        cout << "  ����: " << (morningChoice.empty() ? "���� �������� ����" : morningPlan) << "\n";
        cout << "  ����: " << (afternoonChoice.empty() ? "���� �������� ����" : afternoonPlan) << "\n";
        cout << "--------------------------------------------------------\n\n";

        cout << "[ S ] ��������                         [Enter] ���� ��\n";

        cout << "\n--------------------------------------------------------\n";
        cout << "Current Status\n";

        cout << "  Health     : [";
        for (int i = 0; i < healthBar; i++) cout << "|";
        for (int i = healthBar; i < 20; i++) cout << " ";
        cout << "] " << health << "%" << endl;

        cout << "  Teamwork   : [";
        for (int i = 0; i < teamworkBar; i++) cout << "|";
        for (int i = teamworkBar; i < 20; i++) cout << " ";
        cout << "] " << teamwork << "%" << endl;

        cout << "  Progress   : [";
        for (int i = 0; i < progressBar; i++) cout << "|";
        for (int i = progressBar; i < 20; i++) cout << " ";
        cout << "] " << progress << "%" << endl;

        cout << "========================================================\n";
    }
};