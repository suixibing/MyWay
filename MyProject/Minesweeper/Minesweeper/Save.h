#ifndef _SAVE_H_

#define _SAVE_H_

#define FIRSTSAVE 0
#define LASTSAVE 49

void SaveList(int flag);
void LoadList(int flag);
void SaveData(int row, int col, int mineLeast, int flag);
int LoadData(int *row, int *col, int *mineLeast, int flag);

void Save(int row, int col, int mineLeast);
void Load(int *row, int *col, int *mineLeast);

#endif // _SAVE_H_