#pragma once
#include "stats.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include<time.h>
using namespace std;

class store {
    int currentDay;

public:
    store(int day = 1) : currentDay(day) {
        initializeStats();
    }

    bool print_store() {
        string item_input;
        int item_number = 0;

        while (true) {
            int healthBar = health / 5;
            int teamworkBar = teamwork / 5;
            int progressBar = progress / 5;

            cout << "========================================================\n";
            cout << "                    [Store]                      \n";
            cout << "========================================================\n\n";

            cout << "Item List\n";
            cout << "--------------------------------------------------------\n\n";
            cout << "  [1] 에너지 드링크 (5000원): 체력 회복\n";
            cout << "  [2] 복권 (15000원): \n";
            cout << "--------------------------------------------------------\n\n";

            cout << "Money : " << money << "원" << endl;
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
            cout << "[M] 메인 화면으로 돌아가기\n";
            cout << "구매 할 아이템을 선택하세요: ";
            getline(cin, item_input);

            if (item_input == "m" || item_input == "M") {
                system("cls");
                return true;
            }

            if (item_input == "1") {
                item_number = 1;
            }
            else if (item_input == "2") {
                item_number = 2;
            }
            else {
                cout << "잘못된 입력입니다.\n";
                Sleep(800);
                system("cls");
                continue;
            }

            switch (item_number) {
            case 1:
                if (money >= 5000 && health <= 95) {
                    health += 5;  //
                    money -= 5000;  //에너지 드링크 5000원
                    cout << "(꼴깍) 에너지 드링크를 마셨다. 체력: " << health << "%\n";
                }
                else {
                    cout << "구매할 수 없습니다.\n";
                }
                break;
            case 2:// 확률 3퍼센트에 30만원 - 무조건 뽑는 사람이 손해 보도록
                srand(time(NULL));
                int winning_percentage = rand() % 33; // 0 ~32 난수

                if (money >= 10000) {
                    money -= 15000;
                    if (winning_percentage == 32)
                    {
                        money += 300000;
                        cout << "복권 당첨!!!!!!\n";
                    }
                    else
                    {
                        cout << "(두근 두근) 복권을 구매했다! 꽝이야..\n";
                    }

                }
                else {
                    cout << "구매할 수 없습니다.\n";
                }
                break;
            }

            Sleep(800);
            system("cls");
        }
    }
};