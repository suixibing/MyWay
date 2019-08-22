#pragma once

#ifndef _MAP_H_

#define _MAP_H_

#define MINROW 9
#define MAXROW 24
#define MINCOL 9
#define MAXCOL 30
#define MINMINE 10
#define MAXMINE(row, col) ((row) * (col) - 9)

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
void JumpMap(int row, int col, int mineLeast, Point point, int showPoint, int isFirst);
void MapPrint(int row, int col, int mineLeast, Point point, int showPoint, int isFirst);
void MapOpen(int row, int col, int pointx, int pointy);
int OpenAround(int row, int col, Point point, int mineLeast);
void GameFinish(int row, int col, int mineLeast, int state);
void MapCheck(int row, int col, int mineLeast);


#endif // _MAP_H_