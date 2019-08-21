#pragma once

#ifndef _CONTROL_H_

#define _CONTROL_H_

#define CONTINUE 0
#define OVER 1
#define WIN 2

#define TMP -1

#define SUCCESS 1
#define ERROR 0

#define FALSE 0
#define TRUE 1

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define HIDEPOINT 'h'
#define MINEMARK 'm'
#define MINECHECK 'L'
#define SAVE 'S'
#define ESC 27
#define ENTER 13

enum GameLevel
{
	LEVEL1,
	LEVEL2,
	LEVEL3,
	FREE,
};

enum WelcomeOption
{
	GAMECONTINUE,
	NEWGAME,
	GAMESET,
	EXIT,
};

int GetKeyBoard();
void Game(int row, int col, int mine, int isFirst);
void FreeDefine(int *row, int *col, int *mine);
int Welcome();
int SetLevel();
void Set(int *row, int *col, int *mine);
void GameControl();

#endif // _CONTROL_H_
