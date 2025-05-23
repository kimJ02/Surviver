#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include<cstdlib>
#include<ctime>
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
    int money;  // 돈 변수 추가
    int MorningRandom;
    int AfternoonRandom;

public:
    GameController(int startDay = 1)
        : vm(startDay), st(), nt(), pr(), morningChoice(""), afternoonChoice(""), currentDay(startDay), money(50000), MorningRandom(0), AfternoonRandom(0) {
        initializeStats();
    }
    // 현재 미사용
    /*void applyStatsChange() {
        // 일정에 따른 스탯 변화 적용
        if (morningChoice == "1") {
            money += 10000;
            if(health >= 10) health -= 10;
        }
        else if (morningChoice == "2") {
            if (teamwork <= 90) teamwork += 10;
            if (health >= 10) health -= 10;
        }
        else if (morningChoice == "3") {
            if (progress <= 90) progress += 10;
            if (health >= 10) health -= 10;
        }
        else if (morningChoice == "4") {
            if (teamwork >= 10) teamwork -= 10;
            if (health <= 90) health += 10;
        }

        // 오후 일정에 따른 스탯 변화 적용
        if (afternoonChoice == "1") {
            money += 10000;
            if (health >= 10) health -= 10;
        }
        else if (afternoonChoice == "2") {
            if (teamwork <= 90) teamwork += 10;
            if (health >= 10) health -= 10;
        }
        else if (afternoonChoice == "3") {
            if (progress <= 90) progress += 10;
            if (health >= 10) health -= 10;
        }
        else if (afternoonChoice == "4") {
            if (teamwork >= 10) teamwork -= 10;
            if (health <= 90) health += 10;
        }
    }*/

    void run() {
        string input;

        pr.print_prolog();

        //테스트용
        currentDay = 59;
        srand((unsigned int)time(NULL));

        while (true) {

            //테스트용
            
            MorningRandom = rand() % 10;
            afternoonChoice = rand() % 10;

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
                if (morningChoice == "1") {
                    moneyChange += 10000;
                    healthChange -= 10;

                    // 일정 선택에 따른 이벤트 출력                      숫자 랜덤으로
                    FileIO::printSentenceAt("Story/Work_story.txt", MorningRandom);
                    Sleep(5000);
                    system("cls");
                }
                else if (morningChoice == "2") {
                    healthChange -= 10;
                    teamworkChange += 10;

                    // 일정 선택에 따른 이벤트 출력                      숫자 랜덤으로
                    FileIO::printSentenceAt("Story/Playing_story.txt", MorningRandom);
                    Sleep(5000);
                    system("cls");

                }
                else if (morningChoice == "3") {
                    progressChange += 10;
                    healthChange -= 10;
                }
                else if (morningChoice == "4") {
                    healthChange += 10;
                    teamworkChange -= 10;

                    // 일정 선택에 따른 이벤트 출력                      숫자 랜덤으로
                    FileIO::printSentenceAt("Story/Rest_story.txt", MorningRandom);
                    Sleep(5000);
                    system("cls");
                }

                if (afternoonChoice == "1") {
                    moneyChange += 10000;
                    healthChange -= 10;

                    // 일정 선택에 따른 이벤트 출력                      숫자 랜덤으로
                    FileIO::printSentenceAt("Story/Work_story.txt", AfternoonRandom);
                    Sleep(5000);
                    system("cls");
                }
                else if (afternoonChoice == "2") {
                    healthChange -= 10;
                    teamworkChange += 10;

                    // 일정 선택에 따른 이벤트 출력                      숫자 랜덤으로
                    FileIO::printSentenceAt("Story/Playing_story.txt", AfternoonRandom);
                    Sleep(5000);
                    system("cls");
                }
                else if (afternoonChoice == "3") {
                    progressChange += 10;
                    healthChange -= 10;
                }
                else if (afternoonChoice == "4") {
                    healthChange += 10;
                    teamworkChange -= 10;

                    // 일정 선택에 따른 이벤트 출력                      숫자 랜덤으로
                    FileIO::printSentenceAt("Story/Rest_story.txt", AfternoonRandom);
                    Sleep(5000);
                    system("cls");
                }

                money += moneyChange;
                health += healthChange;
                progress += progressChange;
                teamwork += teamworkChange;

                nt.print_day_result(currentDay, morningChoice, afternoonChoice, money, healthChange, progressChange, teamworkChange, moneyChange);

                cout << "\n[Enter]을 눌러 다음 날로 넘어가기...";
                getline(cin, input);

                currentDay++;
                morningChoice = "";
                afternoonChoice = "";

                system("cls");

                // 날짜(20일 단위)에 따른 이벤트 출력
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

                    // 엔딩 스토리 출력
                    // 스텟에 따라 다른 스토리 나오는 걸로 수정 필요
                    FileIO::printSentenceAt("Story/Ending_story.txt", 0);
                    Sleep(5000);
                    system("cls");
                }

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