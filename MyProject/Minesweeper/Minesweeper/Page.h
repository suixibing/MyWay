#pragma once

#ifndef _PAGE_H_

#define _PAGE_H_

#include<string.h>
#include"Control.h"

#define ARROW_UP    0xE048
#define ARROW_DOWN  0xE050
#define ARROW_LEFT  0xE04B
#define ARROW_RIGHT 0xE04D

#define WELCOMECOLS 40
#define WELCOMELINES 14
#define SETCOLS 36
#define SETLINES 15
#define SAVECOLS 40
#define SAVELINES 14

#define PAGESIZE_COMMOM 1000
#define PAGESIZE_MINE 2000

enum Define
{
	DEFINEHEIGHT,
	DEFINEWIDTH,
	DEFINEMINE,
};

enum Welcome
{
	WELCOMECONTINUE,
	WELCOMENEWGAME,
	WELCOMESET,
	WELCOMEEXIT,
};

void SavePage(int flag);
void SetPage(int flag);
void WelcomePage(int flag);
void DefinePage(int row, int col, int mine, int flag);

#endif // _PAGE_H_