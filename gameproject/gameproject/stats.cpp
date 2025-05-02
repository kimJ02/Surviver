#include "stats.h"
#include <iostream>
using namespace std;

int health;
int progress;
double money;
int teamwork;

void initializeStats() {
    health = 80;
    progress = 0;
    money = 10000.0;
    teamwork = 80;
}

void updateStats(int hpChange, int progChange, double moneyChange, int teamChange) {
    health += hpChange;
    progress += progChange;
    money += moneyChange;
    teamwork += teamChange;

    if (health < 0) health = 0;
    if (progress > 100) progress = 100;
    if (money < 0) money = 0;
    if (teamwork < 0) teamwork = 0;
    if (teamwork > 100) teamwork = 100;
}

void printStats() {
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
