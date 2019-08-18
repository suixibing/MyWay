#pragma once

#ifndef _CONTROL_H_

#define _CONTROL_H_

#define START 0
#define SET 1
#define EXIT 2

int GetKeyBoard();
//void Game(int row, int col, int mine);
void FreeDefine(int *row, int *col, int *mine);
int SetPage();
void Set(int *row, int *col, int *mine);
void GameControl();

#endif // _CONTROL_H_
