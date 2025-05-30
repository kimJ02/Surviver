#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include "visual_main.h"
#include "store.h"
#include "next_day.h"
#include "prolog.h"
#include "stats.h"
#include "FileIO.h"

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

        //테스트용
        currentDay = 1;

        if (currentDay == 1)
        {
            FileIO::printSentenceAt("Story/Day_per_20.txt", 0);
            Sleep(5000);
            system("cls");
        }
        if (currentDay == 20 && progress < 30) // 협력도 조정 해야됨
        {
            FileIO::printSentenceAt("Story/Day_per_20.txt", 1);
            Sleep(5000);
            system("cls");
        }
        else if (currentDay == 20 && progress >= 30)
        {
            FileIO::printSentenceAt("Story/Day_per_20.txt", 2);
            Sleep(5000);
            system("cls");
        }
        if (currentDay == 40 && progress < 50)
        {
            FileIO::printSentenceAt("Story/Day_per_20.txt", 3);
            Sleep(5000);
            system("cls");
        }
        else if (currentDay == 40 && progress >= 50)
        {
            FileIO::printSentenceAt("Story/Day_per_20.txt", 4);
            Sleep(5000);
            system("cls");
        }
        if (currentDay == 60)
        {
            FileIO::printSentenceAt("Story/Day_per_20.txt", 5);
            Sleep(5000);
            system("cls");
        }

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
                    cout << "\n아직 일과를 정하지 않았습니다! 오전과 오후 일정을 먼저 선택해주세요.";
                    Sleep(2000);
                    system("cls");
                    continue;
                }

                system("cls");

                int healthChange = 0, progressChange = 0, teamworkChange = 0, moneyChange = 0;

                if (morningChoice == "1") { // 알바
                    moneyChange += 40000;
                    healthChange -= 10;
                }
                else if (morningChoice == "2") {  // 놀러가기
                    healthChange -= 5;
                    teamworkChange += 10;
                    moneyChange -= 20000;
                }
                else if (morningChoice == "3") {  // 과제
                    progressChange += 2;
                    healthChange -= 10;
                    teamworkChange -= 5;
                }
                else if (morningChoice == "4") {  // 쉬기
                    healthChange += 15;
                    teamworkChange -= 5;
                }

                if (afternoonChoice == "1") {
                    moneyChange += 40000;
                    healthChange -= 10;
                }
                else if (afternoonChoice == "2") {
                    healthChange -= 5;
                    teamworkChange += 10;
                    moneyChange -= 20000;
                }
                else if (afternoonChoice == "3") {
                    progressChange += 2;
                    healthChange -= 10;
                    teamworkChange -= 5;
                }
                else if (afternoonChoice == "4") {
                    healthChange += 15;
                    teamworkChange -= 5;
                }

                money += moneyChange;
                health += healthChange;
                progress += progressChange;
                teamwork += teamworkChange;

                if (health < 0) health = 0;
                if (health > 100) health = 100;

                if (progress < 0) progress = 0;
                if (progress > 100) progress = 100;

                if (teamwork < 0) teamwork = 0;
                if (teamwork > 100) teamwork = 100;

                if (money < 0) money = 0;

                nt.print_day_result(currentDay, morningChoice, afternoonChoice, money, healthChange, progressChange, teamworkChange, moneyChange);

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
                    // 오전 일정 선택 시 조건 검사
                    if (input == "1" && health < 10) {
                        cout << "체력이 부족하여 알바를 할 수 없습니다." << endl;
                        Sleep(3000);
                        system("cls");
                    }
                    else if (input == "2" && money < 20000) {
                        cout << "돈이 부족하여 놀러갈 수 없습니다." << endl;
                        Sleep(3000);
                        system("cls");
                    }
                    else if (input == "3" && health < 10) {
                        cout << "체력이 부족하여 과제를 할 수 없습니다." << endl;
                        Sleep(3000);
                        system("cls");
                    }
                    else {
                        morningChoice = input;
                        vm.setMorningPlan(stoi(morningChoice));
                    }
                }
                else if (afternoonChoice.empty()) {
                    // 오후 일정 선택 시 조건 검사
                    if (input == "1" && health < 10) {
                        cout << "체력이 부족하여 알바를 할 수 없습니다." << endl;
                        Sleep(3000);
                        system("cls");
                    }
                    else if (input == "2" && money < 20000) {
                        cout << "돈이 부족하여 놀러갈 수 없습니다." << endl;
                        Sleep(3000);
                        system("cls");
                    }
                    else if (input == "3" && health < 10) {
                        cout << "체력이 부족하여 과제를 할 수 없습니다." << endl;
                        Sleep(3000);
                        system("cls");
                    }
                    else {
                        afternoonChoice = input;
                        vm.setAfternoonPlan(stoi(afternoonChoice));
                    }
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
