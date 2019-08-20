#ifndef _EXTERN_H_

#define _EXTERN_H_

void SaveList(int flag);
void LoadList();
void SavePage(int flag);
void SaveData(int row, int col, int mineLeast, int flag);
int LoadData(int *row, int *col, int *mineLeast, int flag);

void Save(int row, int col, int mineLeast);
void Load(int *row, int *col, int *mineLeast);

#endif // _EXTERN_H_