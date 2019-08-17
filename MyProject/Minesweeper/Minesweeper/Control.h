#pragma once

#define START 0
#define SET 1
#define EXIT 2

int GetKeyBoard();
void Game(int row, int col, int mine);
void Set(int *row, int *col, int *mine);
void GameControl();