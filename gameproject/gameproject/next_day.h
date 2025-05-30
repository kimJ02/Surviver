#pragma once
#include "stats.h"
#include <iostream>
#include <string>

using namespace std;

class next_day {
public:
    string convertPlan(const string& plan) {
        if (plan == "1") return "알바하기";
        if (plan == "2") return "놀러가기";
        if (plan == "3") return "과제하기";
        if (plan == "4") return "쉬기";
        return "미정";
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

        cout << "오늘의 일과 요약:\n";
        cout << "  오전: " << convertPlan(morningPlan) << "\n";
        cout << "  오후: " << convertPlan(afternoonPlan) << "\n";

        cout << "\n--------------------------------------------------------\n";
        cout << " 스탯 변화 요약:\n\n";

        cout << "  돈       : " << money << "원 (" << (moneyChange > 0 ? "+" : "") << moneyChange << ")\n";

        cout << "  체력     : [";
        for (int i = 0; i < healthBar; i++) cout << "|";
        for (int i = healthBar; i < 10; i++) cout << " ";
        cout << "] " << health << "% (" << (healthChange > 0 ? "+" : "") << healthChange << "%)\n";

        cout << "  진행도   : [";
        for (int i = 0; i < progressBar; i++) cout << "|";
        for (int i = progressBar; i < 20; i++) cout << " ";
        cout << "] " << progress << "% (" << (progressChange > 0 ? "+" : "") << progressChange << "%)\n";

        cout << "  협력도   : [";
        for (int i = 0; i < teamworkBar; i++) cout << "|";
        for (int i = teamworkBar; i < 20; i++) cout << " ";
        cout << "] " << teamwork << "% (" << (teamworkChange > 0 ? "+" : "") << teamworkChange << "%)\n";

        cout << "\n========================================================\n";
        //cout << "[Enter]을 눌러 다음 날로 넘어가기...";
    }
};