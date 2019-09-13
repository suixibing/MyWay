#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 4//胜利条件，即几颗棋子相连时胜利
#define ROW 10//行数
#define COL 10//列数
#define PLAYER '*'//玩家的棋子
#define COMPUTER '#'//电脑的棋子
#define CONTINUE 'C'//用于函数返回，表示继续
#define END 'Q'//表示游戏结束

void Menu();//打印菜单
void Play();//游戏函数，主要用于调用定义的各种函数
void Display(char board[ROW][COL], int row, int col);//打印棋盘
void PlayerMove(char board[ROW][COL], int row, int col);//玩家下棋
void ComputerMove(char board[ROW][COL], int row, int col);//电脑下棋
char CheckWin(char board[ROW][COL], int row, int col);//判断胜利条件是否满足

