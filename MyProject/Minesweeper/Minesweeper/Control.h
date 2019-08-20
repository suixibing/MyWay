#pragma once

#ifndef _CONTROL_H_

#define _CONTROL_H_

#define CONTINUE 0
#define OVER 1
#define WIN 2

#define HIDEPOINT 'h'
#define MINEMARK 'm'
#define MINECHECK 'l'
#define ESC 27

enum Welcome
{
	GAMECONTINUE,
	NEWGAME,
	GAMESET,
	EXIT,
};

int GetKeyBoard();
int Game(int row, int col, int mine, int isNew);
void FreeDefine(int *row, int *col, int *mine);
int SetPage();
void Set(int *row, int *col, int *mine);
void GameControl();

#endif // _CONTROL_H_
