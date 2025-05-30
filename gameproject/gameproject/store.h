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
            cout << "  [1] ������ �帵ũ (5000��): ü�� ȸ��\n";
            cout << "  [2] ���� (15000��): \n";
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
                if (money >= 5000 && health <= 95) {
                    health += 5;  //
                    money -= 5000;  //������ �帵ũ 5000��
                    cout << "(�ñ�) ������ �帵ũ�� ���̴�. ü��: " << health << "%\n";
                }
                else {
                    cout << "������ �� �����ϴ�.\n";
                }
                break;
            case 2:// Ȯ�� 3�ۼ�Ʈ�� 30���� - ������ �̴� ����� ���� ������
                srand(time(NULL));
                int winning_percentage = rand() % 33; // 0 ~32 ����

                if (money >= 10000) {
                    money -= 15000;
                    if (winning_percentage == 32)
                    {
                        money += 300000;
                        cout << "���� ��÷!!!!!!\n";
                    }
                    else
                    {
                        cout << "(�α� �α�) ������ �����ߴ�! ���̾�..\n";
                    }

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