#ifndef _SAVE_H_

#define _SAVE_H_

#include<time.h>
#include<string.h>
#include"Control.h"

#define FIRSTSAVE 0
#define LASTSAVE 99
#define MAXSAVENUM (LASTSAVE - FIRSTSAVE + 1)

#define LISTLINES 10

#define GAMELOAD 0
#define GAMESAVE 1

void InitNullList();
int LoadList();
void SaveList(int flag);
void SaveData(int row, int col, int mineLeast, int flag);
int LoadData(int *row, int *col, int *mineLeast, int flag);

void Save(int row, int col, int mineLeast);
void SaveOrLoad(int *row, int *col, int *mineLeast, int isSave);

#endif // _SAVE_H_