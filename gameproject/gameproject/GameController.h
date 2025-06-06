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
#include "Event_imageIO.h"
#include "ending_image2.h"

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
            cout << "\n" << endl;
            ProimagIO::printSentenceAt("Story/professor_image.txt", 2);
            getline(cin, input);
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

                    Event_imageIO::printSentenceAt("Story/Parttimejob_Image.txt", 0);
                    cout << "\n============================================================================================================================================================\n" << endl;                   
                    FileIO::printSentenceAt("Story/Part_time_job_story.txt", Random);
                   

                    if (Random == 0 || Random == 1) moneyChange -= 40000;            // 0,1 �̺�Ʈ�� money_change 0 , //  8,9 �̺�Ʈ��  money_change +80000��
                    else if (Random == 8 || Random == 9) moneyChange += 40000;

                    getline(cin, input);
                }
                else if (morningChoice == "2") {
                    healthChange -= 5;
                    teamworkChange += 10;
                    moneyChange -= 20000;

                    Event_imageIO::printSentenceAt("Story/Parttimejob_Image.txt", 1);
                    cout << "\n============================================================================================================================================================\n" << endl;
                    FileIO::printSentenceAt("Story/Playing_story.txt", Random);
                    if (Random == 0 || Random == 1) teamworkChange -= 5;           // 0,1 �̺�Ʈ�� teamworkChange +5 , //  8,9 �̺�Ʈ��  teamworkChange +15
                    else if (Random == 8 || Random == 9) teamworkChange += 5;

                    getline(cin, input);
                }
                else if (morningChoice == "3") {
                    if (teamwork >= 70)
                    {
                        progressChange += 5;
                    }
                    else
                    {
                        progressChange += 2;
                    }
                    healthChange -= 10;
                    teamworkChange -= 5; 
                    Event_imageIO::printSentenceAt("Story/Parttimejob_Image.txt", 2);
                    cout << "\n============================================================================================================================================================\n" << endl;
                    FileIO::printSentenceAt("Story/Work_story.txt", Random);
                    getline(cin, input);
                }
                else if (morningChoice == "4") {
                    healthChange += 15;
                    teamworkChange -= 5;
                    Event_imageIO::printSentenceAt("Story/Parttimejob_Image.txt", 3);
                    cout << "\n============================================================================================================================================================\n" << endl;
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
                    {
                        FileIO::printSentenceAt("Story/Day_per_20.txt", 1);
                        ProimagIO::printSentenceAt("Story/professor_image.txt", 1);
                    }
                    else {
                        FileIO::printSentenceAt("Story/Day_per_20.txt", 2);
                        ProimagIO::printSentenceAt("Story/professor_image.txt", 3);
                    }
                        
                    Sleep(5000); getline(cin, input); system("cls");
                }
                else if (currentDay == 40) {
                    if (progress < 50) {
                        FileIO::printSentenceAt("Story/Day_per_20.txt", 3);
                        ProimagIO::printSentenceAt("Story/professor_image.txt", 1); // ������ ���� �������� 
                    }
                    else{
                        FileIO::printSentenceAt("Story/Day_per_20.txt", 4);
                        ProimagIO::printSentenceAt("Story/professor_image.txt", 4); 
                    }
                        
                    Sleep(5000); getline(cin, input); system("cls");
                }
                else if (currentDay == 60 || progress == 100) {
                    FileIO::printSentenceAt("Story/Day_per_20.txt", 5);
                    Sleep(5000); getline(cin, input); system("cls");

                    if (progress <= 100 && progress > 90) {
                        FileIO::printSentenceAt("Story/Ending_story.txt", 0);
                        Ending_Image(1);
                        getline(cin, input);
                        break;
                    }
                    else if (progress <= 90 && progress > 80) {
                        FileIO::printSentenceAt("Story/Ending_story.txt", 1);
                        Ending_Image(2);
                        getline(cin, input);
                        break;
                    }
                    else if (progress <= 80 && progress > 70) {
                        FileIO::printSentenceAt("Story/Ending_story.txt", 2);
                        Ending_Image(3);
                        getline(cin, input);
                        break;
                    }
                    else if (progress <= 70 && progress > 60) {
                        FileIO::printSentenceAt("Story/Ending_story.txt", 3);
                        Ending_Image(4);
                        getline(cin, input);
                        break;
                    }
                    else if (progress <= 60) {
                        cout << "............" << endl;
                        Sleep(5000); system("cls");
                        Ending_Image(5);
                        Sleep(200); system("cls");
                        Ending_Image(6);
                        Sleep(200); system("cls");
                        Ending_Image(7);
                        Sleep(200); system("cls");
                        Ending_Image(8);
                        Sleep(200); system("cls");
                        Ending_Image(9);
                        Sleep(200); system("cls");
                        Ending_Image(10);
                        Sleep(2000); system("cls");
                        FileIO::printSentenceAt("Story/Ending_story.txt", 4);
                        Ending_Image(11);
                        getline(cin, input);
                        break;
                    }
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
                        Sleep(3000);
                    }
                    else if (input == "2" && money < 20000) {
                        cout << "���� �����Ͽ� ��� �� �����ϴ�." << endl;
                        Sleep(3000);
                    }
                    else if (input == "3" && health < 10) {
                        cout << "ü���� �����Ͽ� ������ �� �� �����ϴ�." << endl;
                        Sleep(3000);
                    }
                    else if (input == "3" && teamwork < 5) {
                        cout << "����ũ�� ���� ������ �� �� �����ϴ�." << endl;
                        Sleep(3000);
                    }
                    else if (input == "4" && teamwork < 5) {
                        cout << "����ũ�� ���� �� �� �����ϴ�." << endl;
                        Sleep(3000);
                    }
                    else {
                        morningChoice = input;
                        vm.setMorningPlan(stoi(input));
                    }

                    system("cls");
                }
                else if (afternoonChoice.empty()) {
                    if (input == "1" && health < 10) {
                        cout << "ü���� �����Ͽ� �˹ٸ� �� �� �����ϴ�." << endl;
                        Sleep(3000);
                    }
                    else if (input == "2" && money < 20000) {
                        cout << "���� �����Ͽ� ��� �� �����ϴ�." << endl;
                        Sleep(3000);
                    }
                    else if (input == "3" && health < 10) {
                        cout << "ü���� �����Ͽ� ������ �� �� �����ϴ�." << endl;
                        Sleep(3000);
                    }
                    else if (input == "3" && teamwork < 5) {
                        cout << "����ũ�� ���� ������ �� �� �����ϴ�." << endl;
                        Sleep(3000);
                    }
                    else if (input == "4" && teamwork < 5) {
                        cout << "����ũ�� ���� �� �� �����ϴ�." << endl;
                        Sleep(3000);
                    }
                    else {
                        afternoonChoice = input;
                        vm.setAfternoonPlan(stoi(input));
                    }

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