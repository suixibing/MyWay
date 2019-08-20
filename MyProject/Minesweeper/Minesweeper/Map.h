#pragma once

#ifndef _MAP_H_

#define _MAP_H_

#define MAXROW 24
#define MINROW 9
#define MAXCOL 30
#define MINCOL 9
#define MINMINE 10

#define NOTFIRST 0
#define FIRST 1

enum
{
	BLANK,
	MINE = -1,
};

enum STATE
{
	COVERED,
	MARKED,
	OPENED,
};

typedef struct Point
{
	int row;
	int col;
}Point;

void MapInit(int row, int col, int mine, Point point);
void MapPrint(int row, int col, int mineLeast, Point point, int flag, int isFirst);
void MapOpen(int row, int col, int pointx, int pointy);
int OpenAround(int row, int col, Point point, int mineLeast);
void GameOver(int row, int col, int mineLeast);
void GameWin(int row, int col, int mineLeast);
void MapCheck(int row, int col, int mineLeast);


#endif // _MAP_H_