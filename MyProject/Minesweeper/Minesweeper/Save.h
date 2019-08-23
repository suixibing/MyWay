#ifndef _SAVE_H_

#define _SAVE_H_

#include<time.h>
#include<string.h>
#include"Control.h"

#define FIRSTSAVE 0
#define LASTSAVE 99
#define MAXSAVENUM (LASTSAVE - FIRSTSAVE + 1)

#define LISTLINES 10

void LoadList();
void SaveList(int flag);
void SaveData(int row, int col, int mineLeast, int flag);
int LoadData(int *row, int *col, int *mineLeast, int flag);

void Save(int row, int col, int mineLeast);
void Load(int *row, int *col, int *mineLeast);

#endif // _SAVE_H_