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

        string comment1 = "알바를 하다가 손님이 많아서 퇴근이 늦었다...";
        string comment2 = "보너스를 받았지만 너무 힘들다... \n\nGithub에서 보물을 발견했다!\n코드를 참조할 수 있어서 오늘은 수월했어.";

        int healthBar = health / 5;
        int progressBar = progress / 5;

        cout << "========================================================\n";
        cout << "                     결과 요약\n";
        cout << "========================================================\n\n";

        cout << "오늘의 일과\n";
        cout << "  오전: 알바\n";
        cout << "  오후: 과제하기\n";

        cout << "\n--------------------------------------------------------\n";
        cout << " 스탯 변화 요약:\n\n";

        cout << "  체력     : [";
        for (int i = 0; i < healthBar; i++) cout << "|";
        for (int i = healthBar; i < 10; i++) cout << " ";
        cout << "] " << health << "%  (" << (healthChange > 0 ? "+" : "") << healthChange << "%)\n";

        cout << "  완성도   : [";
        for (int i = 0; i < progressBar; i++) cout << "|";
        for (int i = progressBar; i < 20; i++) cout << " ";
        cout << "] " << progress << "%  (" << (progressChange > 0 ? "+" : "") << progressChange << "%)\n";

        cout << " 돈     : " << moneyChange << " 증가\n";

        cout << "\n--------------------------------------------------------\n";
        cout << " 코멘트:\n";
        cout << comment1 << endl;
        cout << comment2 << endl;

        cout << "\n========================================================\n";
        cout << "[Enter] 다음 날로 넘어가기\n";
        cout << "========================================================\n";
    }
};