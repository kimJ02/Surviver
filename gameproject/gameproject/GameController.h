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
    int money;  // �� ���� �߰�

public:
    GameController(int startDay = 1)
        : vm(startDay), st(), nt(), pr(), morningChoice(""), afternoonChoice(""), currentDay(startDay), money(50000) {
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

        while (true) {
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
                }
                else if (morningChoice == "2") {
                    healthChange -= 10;
                    teamworkChange += 10;
                }
                else if (morningChoice == "3") {
                    progressChange += 10;
                    healthChange -= 10;
                }
                else if (morningChoice == "4") {
                    healthChange += 10;
                    teamworkChange -= 10;
                }

                if (afternoonChoice == "1") {
                    moneyChange += 10000;
                    healthChange -= 10;
                }
                else if (afternoonChoice == "2") {
                    healthChange -= 10;
                    teamworkChange += 10;
                }
                else if (afternoonChoice == "3") {
                    progressChange += 10;
                    healthChange -= 10;
                }
                else if (afternoonChoice == "4") {
                    healthChange += 10;
                    teamworkChange -= 10;
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