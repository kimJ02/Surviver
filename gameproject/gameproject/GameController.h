#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "visual_main.h"
#include "store.h"
#include "next_day.h"
#include "prolog.h"
#include "stats.h"
#include "FileIO.h"
#include "ProimagIO.h"

using namespace std;

class GameController {
    visual_main vm;
    store st;
    next_day nt;
    prolog pr;
    string morningChoice;
    string afternoonChoice;
    int currentDay;
    int Random;

public:
    GameController(int startDay = 1)
        : vm(startDay), st(), nt(), pr(), morningChoice(""), afternoonChoice(""), currentDay(startDay), Random(0) {
        initializeStats();
    }

    void run() {
        string input;

        pr.print_prolog();

        srand(static_cast<unsigned int>(time(NULL)));

        // Day 1 ������
        if (currentDay == 1) {
            FileIO::printSentenceAt("Story/Day_per_20.txt", 0);
            ProimagIO::printSentenceAt("Story/professor_image.txt", 1);
            Sleep(5000);
            system("cls");
        }

        while (true) {
            Random = rand() % 10;

            vm.printUI(morningChoice, afternoonChoice, currentDay);

            cout << "\n������ �����ϼ��� (1~4) �Ǵ� [S]����, [Enter] ������, [q] ����: ";
            getline(cin, input);

            if (input == "q" || input == "Q") {
                cout << "\n������ �����մϴ�.\n";
                break;
            }

            else if (input.empty()) {
                if (morningChoice.empty() || afternoonChoice.empty()) {
                    cout << "\n���� �ϰ��� ������ �ʾҽ��ϴ�! ������ ���� ������ ���� �������ּ���.";
                    Sleep(2000);
                    system("cls");
                    continue;
                }

                system("cls");

                int healthChange = 0, progressChange = 0, teamworkChange = 0, moneyChange = 0;

                // ���� ���� ó��
                if (morningChoice == "1") {
                    moneyChange += 40000;
                    healthChange -= 10;
                    FileIO::printSentenceAt("Story/Part_time_job_story.txt", Random);
                    getline(cin, input);
                }
                else if (morningChoice == "2") {
                    healthChange -= 5;
                    teamworkChange += 10;
                    moneyChange -= 20000;
                    FileIO::printSentenceAt("Story/Playing_story.txt", Random);
                    getline(cin, input);
                }
                else if (morningChoice == "3") {
                    progressChange += 2;
                    healthChange -= 10;
                    teamworkChange -= 5;
                    FileIO::printSentenceAt("Story/Work_story.txt", Random);
                    getline(cin, input);
                }
                else if (morningChoice == "4") {
                    healthChange += 15;
                    teamworkChange -= 5;
                    FileIO::printSentenceAt("Story/Rest_story.txt", Random);
                    getline(cin, input);
                }

                // ���� ���� ó��
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

                // ���� �ݿ�
                money += moneyChange;
                health += healthChange;
                progress += progressChange;
                teamwork += teamworkChange;

                // ���� ���� ����
                if (health < 0) health = 0;
                if (health > 100) health = 100;
                if (progress < 0) progress = 0;
                if (progress > 100) progress = 100;
                if (teamwork < 0) teamwork = 0;
                if (teamwork > 100) teamwork = 100;
                if (money < 0) money = 0;

                nt.print_day_result(currentDay, morningChoice, afternoonChoice, money, healthChange, progressChange, teamworkChange, moneyChange);

                cout << "\n[Enter]�� ���� ���� ���� �Ѿ��...";
                getline(cin, input);

                currentDay++;
                morningChoice = "";
                afternoonChoice = "";

                system("cls");

                // 20�� ���� �̺�Ʈ
                if (currentDay == 20) {
                    if (progress < 30)
                        FileIO::printSentenceAt("Story/Day_per_20.txt", 1);
                    
                    else
                        FileIO::printSentenceAt("Story/Day_per_20.txt", 2);
                    Sleep(5000); getline(cin, input); system("cls");
                }
                else if (currentDay == 40) {
                    if (progress < 50)
                        FileIO::printSentenceAt("Story/Day_per_20.txt", 3);
                    else
                        FileIO::printSentenceAt("Story/Day_per_20.txt", 4);
                    Sleep(5000); getline(cin, input); system("cls");
                }
                else if (currentDay == 60) {
                    FileIO::printSentenceAt("Story/Day_per_20.txt", 5);
                    Sleep(5000); getline(cin, input);

                    // ����
                    FileIO::printSentenceAt("Story/Ending_story.txt", 0); // TODO: ���Ⱥ��� �ٸ� ���� �߰�
                    getline(cin, input);
                    break;
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
                // ���� ���� �� ���� �˻�
                if (morningChoice.empty()) {
                    if (input == "1" && health < 10) {
                        cout << "ü���� �����Ͽ� �˹ٸ� �� �� �����ϴ�." << endl;
                    }
                    else if (input == "2" && money < 20000) {
                        cout << "���� �����Ͽ� ��� �� �����ϴ�." << endl;
                    }
                    else if (input == "3" && health < 10) {
                        cout << "ü���� �����Ͽ� ������ �� �� �����ϴ�." << endl;
                    }
                    else {
                        morningChoice = input;
                        vm.setMorningPlan(stoi(input));
                    }
                    Sleep(3000);
                    system("cls");
                }
                else if (afternoonChoice.empty()) {
                    if (input == "1" && health < 10) {
                        cout << "ü���� �����Ͽ� �˹ٸ� �� �� �����ϴ�." << endl;
                    }
                    else if (input == "2" && money < 20000) {
                        cout << "���� �����Ͽ� ��� �� �����ϴ�." << endl;
                    }
                    else if (input == "3" && health < 10) {
                        cout << "ü���� �����Ͽ� ������ �� �� �����ϴ�." << endl;
                    }
                    else {
                        afternoonChoice = input;
                        vm.setAfternoonPlan(stoi(input));
                    }
                    Sleep(3000);
                    system("cls");
                }
            }

            else {
                cout << "\n�߸��� �Է��Դϴ�. �ùٸ� �ɼ��� �����ϼ���.\n";
                Sleep(2000);
                system("cls");
            }
        }
    }
};