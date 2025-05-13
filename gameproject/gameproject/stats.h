#pragma once
#ifndef STATS_H
#define STATS_H

extern int health;
extern int progress; 
extern double money;
extern int teamwork;

void initializeStats();
void updateStats(int hpChange, int progChange, double moneyChange, int teamChange);
void printStats();

#endif // STATS_H
