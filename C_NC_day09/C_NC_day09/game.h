#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 9
#define COL 9
#define MINE_NUM 10
#define EXIT -10000
#define MINE '*'
#define GRASS '*'
#define START 1
#define END 0
#define ERROR -1

void Menu();
void Play();
void UpdateMineMap(char mine_map[ROW][COL], int row, int col, int now_row, int now_col);
void Init(char play_map[ROW][COL], char mine_map[ROW][COL], int row, int col, int mine);
void ShowMap(char play_map[ROW][COL], int row, int col);
int UpdatePlayMap(char play_map[ROW][COL], char mine_map[ROW][COL],
	int row, int col, int now_row, int now_col);
int Player(char play_map[ROW][COL], char mine_map[ROW][COL], int row, int col);

