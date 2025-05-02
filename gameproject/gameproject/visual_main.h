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
        case 1: return "알바하기";
        case 2: return "놀러가기";
        case 3: return "과제하기";
        case 4: return "쉬기";
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

        cout << "오늘 할 일과를 선택하세요.\n";
        cout << "  [1] 알바하기\n";
        cout << "  [2] 놀러가기\n";
        cout << "  [3] 과제하기\n";
        cout << "  [4] 쉬기\n";

        cout << "\n--------------------------------------------------------\n";
        cout << "Today's Plan\n";
        cout << "  오전: " << (morningChoice.empty() ? "아직 선택하지 않음" : morningPlan) << "\n";
        cout << "  오후: " << (afternoonChoice.empty() ? "아직 선택하지 않음" : afternoonPlan) << "\n";
        cout << "--------------------------------------------------------\n\n";

        cout << "[ S ] 상점열기                         [Enter] 다음 날\n";

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