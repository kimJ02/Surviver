#pragma once
#include <iostream>
using namespace std;

class Status {
protected:
    int money;
    int health;
    int teamwork;
    int progress;

public:
	Status(int hp = 80, int tm = 80, int pr = 0, int gold = 10000)
		: health(hp), teamwork(tm), progress(pr), money(gold) {}
    void PrintStauts()
    {
		int healthBar = health / 5;
		int teamworkBar = teamwork / 5;
		int progressBar = progress / 5;

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
    }
};
