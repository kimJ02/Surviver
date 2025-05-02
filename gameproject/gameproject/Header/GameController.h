#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include "visual_main.h"
#include "store.h"
#include "next_day.h"
#include "prolog.h"
#include "stats.h"

using namespace std;

class GameController {
    visual_main vm;
    store st;
    next_day nt;
    prolog pr;
    string morningChoice;
    string afternoonChoice;
    int currentDay;

public:
    GameController(int startDay = 1)
        : vm(startDay), st(), nt(), pr(), morningChoice(""), afternoonChoice(""), currentDay(startDay) {
        initializeStats();
    }

    void run() {
        string input;

        pr.print_prolog();

        while (true) {
            vm.printUI(morningChoice, afternoonChoice, currentDay);

            cout << "\n일정을 선택하세요 (1~4) 또는 [S]상점, [Enter] 다음날, [q] 종료: ";
            getline(cin, input);

            if (input == "q" || input == "Q") {
                cout << "\n게임을 종료합니다.\n";
                break;
            }

            else if (input.empty()) {
                if (morningChoice.empty() || afternoonChoice.empty()) {
                    cout << "\n아직 일과를 정하지 않았습니다! 오전과 오후 일정을 먼저 선택해주세요.\n";
                    Sleep(2000);
                    system("cls");
                    continue;
                }

                system("cls");


                nt.print_day_result(currentDay, morningChoice, afternoonChoice);

                cout << "\n[Enter]을 눌러 다음 날로 넘어가기...";
                getline(cin, input);

                currentDay++;
                morningChoice = "";
                afternoonChoice = "";

                system("cls");
                continue;
            }

            else if (input == "S" || input == "s") {
                system("cls");
                if (st.print_store()) {
                    system("cls");
                    continue;
                }
            }

            else if (input == "1" || input == "2" || input == "3" || input == "4") {
                if (morningChoice.empty()) {
                    morningChoice = input;
                    vm.setMorningPlan(stoi(morningChoice));
                }
                else if (afternoonChoice.empty()) {
                    afternoonChoice = input;
                    vm.setAfternoonPlan(stoi(afternoonChoice));
                }
            }

            else {
                cout << "\n잘못된 입력입니다. 올바른 옵션을 선택하세요.\n";
                Sleep(2000);
                system("cls");
            }
        }
    }
};