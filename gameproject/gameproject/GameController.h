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
    int money;  // �� ���� �߰�
    int MorningRandom;
    int AfternoonRandom;

public:
    GameController(int startDay = 1)
        : vm(startDay), st(), nt(), pr(), morningChoice(""), afternoonChoice(""), currentDay(startDay), money(50000), MorningRandom(0), AfternoonRandom(0) {
        initializeStats();
    }
    // ���� �̻��
    /*void applyStatsChange() {
        // ������ ���� ���� ��ȭ ����
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

        // ���� ������ ���� ���� ��ȭ ����
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

        //�׽�Ʈ��
        currentDay = 59;
        srand((unsigned int)time(NULL));

        while (true) {

            //�׽�Ʈ��
            
            MorningRandom = rand() % 10;
            afternoonChoice = rand() % 10;

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
                if (morningChoice == "1") {
                    moneyChange += 10000;
                    healthChange -= 10;

                    // ���� ���ÿ� ���� �̺�Ʈ ���                      ���� ��������
                    FileIO::printSentenceAt("Story/Work_story.txt", MorningRandom);
                    Sleep(5000);
                    system("cls");
                }
                else if (morningChoice == "2") {
                    healthChange -= 10;
                    teamworkChange += 10;

                    // ���� ���ÿ� ���� �̺�Ʈ ���                      ���� ��������
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

                    // ���� ���ÿ� ���� �̺�Ʈ ���                      ���� ��������
                    FileIO::printSentenceAt("Story/Rest_story.txt", MorningRandom);
                    Sleep(5000);
                    system("cls");
                }

                if (afternoonChoice == "1") {
                    moneyChange += 10000;
                    healthChange -= 10;

                    // ���� ���ÿ� ���� �̺�Ʈ ���                      ���� ��������
                    FileIO::printSentenceAt("Story/Work_story.txt", AfternoonRandom);
                    Sleep(5000);
                    system("cls");
                }
                else if (afternoonChoice == "2") {
                    healthChange -= 10;
                    teamworkChange += 10;

                    // ���� ���ÿ� ���� �̺�Ʈ ���                      ���� ��������
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

                    // ���� ���ÿ� ���� �̺�Ʈ ���                      ���� ��������
                    FileIO::printSentenceAt("Story/Rest_story.txt", AfternoonRandom);
                    Sleep(5000);
                    system("cls");
                }

                money += moneyChange;
                health += healthChange;
                progress += progressChange;
                teamwork += teamworkChange;

                nt.print_day_result(currentDay, morningChoice, afternoonChoice, money, healthChange, progressChange, teamworkChange, moneyChange);

                cout << "\n[Enter]�� ���� ���� ���� �Ѿ��...";
                getline(cin, input);

                currentDay++;
                morningChoice = "";
                afternoonChoice = "";

                system("cls");

                // ��¥(20�� ����)�� ���� �̺�Ʈ ���
                if (currentDay == 1)
                {
                    FileIO::printSentenceAt("Story/Day_per_20.txt", 0);
                    Sleep(5000);
                    system("cls");
                }
                if (currentDay == 20 && progress < 30) // ���µ� ���� �ؾߵ�
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

                    // ���� ���丮 ���
                    // ���ݿ� ���� �ٸ� ���丮 ������ �ɷ� ���� �ʿ�
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
                cout << "\n�߸��� �Է��Դϴ�. �ùٸ� �ɼ��� �����ϼ���.\n";
                Sleep(2000);
                system("cls");
            }
        }
    }
};