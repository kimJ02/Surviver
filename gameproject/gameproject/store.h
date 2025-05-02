#pragma once
#include "stats.h"
#include <iostream>
#include <Windows.h>

using namespace std;

class store {
    int currentDay;

public:
    store(int day = 1) : currentDay(day) {
        initializeStats();
    }

    bool print_store() {
        string item_input;
        int dDay = 60 - currentDay;
        int item_number = 0;

        while (true) {
            int healthBar = health / 5;
            int teamworkBar = teamwork / 5;
            int progressBar = progress / 5;

            cout << "========================================================\n";
            cout << "                    [Day " << currentDay << "  D-" << dDay << "]                      \n";
            cout << "========================================================\n\n";

            cout << "Item List\n";
            cout << "--------------------------------------------------------\n\n";
            cout << "  [1] ������ �帵ũ (2000��): ü�� ȸ��\n";
            cout << "  [2] ���� (1000��): ���� ���� ��Ʈ \n";
            cout << "--------------------------------------------------------\n\n";

            cout << "Money : " << money << "��" << endl;
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
            cout << "[M] ���� ȭ������ ���ư���\n";
            cout << "���� �� �������� �����ϼ���: ";
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
                cout << "�߸��� �Է��Դϴ�.\n";
                Sleep(800);
                system("cls");
                continue;
            }

            switch (item_number) {
            case 1:
                if (money >= 2000 && health <= 90) {
                    health += 10;
                    money -= 2000;
                    cout << "(�ñ�) ������ �帵ũ�� ���̴�. ü��: " << health << "%\n";
                }
                else {
                    cout << "������ �� �����ϴ�.\n";
                }
                break;
            case 2:
                if (money >= 1000) {
                    money -= 1000;
                    cout << "(�α� �α�) ������ �����ߴ�! ���̾�..\n";
                }
                else {
                    cout << "������ �� �����ϴ�.\n";
                }
                break;
            }

            Sleep(800);
            system("cls");
        }
    }
};