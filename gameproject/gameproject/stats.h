#pragma once
#ifndef STATS_H
#define STATS_H

extern int health;    // 기본값: 100
extern int progress;  // 기본값: 0
extern double money;  // 기본값: 10000
extern int teamwork;  // 기본값: 80

void initializeStats();
void updateStats(int hpChange, int progChange, double moneyChange, int teamChange);
void printStats();

#endif // STATS_H
