#pragma once

#ifndef _PAGE_H_

#define _PAGE_H_

#define ARROW_UP    0xE048
#define ARROW_DOWN  0xE050
#define ARROW_LEFT  0xE04B
#define ARROW_RIGHT 0xE04D

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