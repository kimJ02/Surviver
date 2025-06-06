#pragma once
#include "stats.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class store {
    int currentDay;

public:
    store(int day = 1) : currentDay(day) {
        initializeStats();
        srand((unsigned int)time(NULL)); // ���� �ʱ�ȭ
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
            cout << "  [1] ������ �帵ũ (5000��): ��ģ ���� �� ĵ�� Ȱ��! ü�� +5\n";
            cout << "  [2] ���� (15000��): �� �λ����� ������ ����� �ζǻ��̴�.\n";
            cout << "  [3] ���� (7000��): ���� �� �� �ο���. ���µ� +5\n";
            cout << "--------------------------------------------------------\n\n";

            cout << "  Money : " << money << "��" << endl;
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
            else if (item_input == "3") {
                item_number = 3;
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
                    health += 5;
                    money -= 5000;
                    cout << "(�ñ�) ������ �帵ũ�� ���̴�." << endl;
                    cout << "ü��: " << health << "%\n";
                }
                else {
                    cout << "������ �� �����ϴ�.\n";
                }
                break;
            case 2:
                if (money >= 15000) {
                    money -= 15000;
                    int winning_percentage = rand() % 33;
                    if (winning_percentage == 32) {
                        money += 300000;
                        cout << "���� ��÷!!!!!!\n";
                        cout << "�λ� �����ϱ� �λ� �����ϱ�..?\n";
                    }
                    else {
                        cout << "(�α� �α�) ������ �����ߴ�!\n";
                        cout << " ���̾�..\n";
                    }
                }
                else {
                    cout << "������ �� �����ϴ�.\n";
                }
                break;
            case 3:
                if (money >= 7000 && teamwork <= 95) {
                    teamwork += 5;
                    money -= 7000;
                    cout << "������ ����ϴ� �������� ���ؼ� ������ �簬��! ��ε� �⻵�ϴ� �� ����!" << endl;
                    cout << "���µ�: " << teamwork << "%\n";
                }
                else {
                    cout << "������ �� �����ϴ�.\n";
                }
                break;
            }

            Sleep(1500);
            system("cls");
        }
    }
};