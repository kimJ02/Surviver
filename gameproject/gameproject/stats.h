#pragma once
#ifndef STATS_H
#define STATS_H

extern int health;    // �⺻��: 100
extern int progress;  // �⺻��: 0
extern double money;  // �⺻��: 10000
extern int teamwork;  // �⺻��: 80

void initializeStats();
void updateStats(int hpChange, int progChange, double moneyChange, int teamChange);
void printStats();

#endif // STATS_H
