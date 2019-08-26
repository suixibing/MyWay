#pragma once

#ifndef _CONTROL_H_

#define _CONTROL_H_

#include <conio.h>
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include"Map.h"
#include"Page.h"
#include"Save.h"

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
#define JUMP 'J'
#define ESC 27
#define ENTER 13

#define MODE_KEYBOARD 'K'
#define MODE_MOUSE 'M'

#define INITIALROWS 16
#define INITIALCOLS 16
#define INITIALMINES 40

#define BOUNDJUDGE(x, min, max) ((x) < (min) ? (min) : ((x) > (max) ? (max) : (x)))
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)

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
void HideCursor();
void Gotoxy(int x, int y);
void SetConsoleSize(int cols, int lines);

int GetMouse(int *row, int *col);
void Game(int row, int col, int mine, int isFirst);
void FreeDefine(int *row, int *col, int *mine);
int Welcome();
int SetLevel();
void Set(int *row, int *col, int *mine);
void GameControl();

#endif // _CONTROL_H_
