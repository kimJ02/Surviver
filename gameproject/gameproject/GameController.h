#pragma once
#include <iostream>
#include <string>
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

public:
    GameController(int startDay = 1)
        : vm(startDay), st(), nt(), pr(), morningChoice(""), afternoonChoice("") {
        initializeStats();
    }

    void run() {
        string input;

        pr.print_prolog();

        while (true) {
            vm.printUI(morningChoice, afternoonChoice);

            cout << "\n일정을 선택하세요 (1~4) 또는 [S]상점, [q] 종료: ";
            getline(cin, input);

            if (input == "q" || input == "Q") {
                cout << "\n게임을 종료합니다.\n";
                break;
            }
            else if (input == "S" || input == "s") {
                system("cls");
                if (st.print_store()) {
                    system("cls");
                    continue;
                }
            }
            else if (morningChoice.empty()) {
                morningChoice = input;
                vm.setMorningPlan(stoi(morningChoice));
            }
            else if (afternoonChoice.empty()) {
                afternoonChoice = input;
                vm.setAfternoonPlan(stoi(afternoonChoice));
            }
        }
    }
};