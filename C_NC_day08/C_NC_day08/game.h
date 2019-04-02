#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 3
#define ROW 6
#define COL 6
#define PLAYER '*'
#define COMPUTER '#'
#define CONTINUE 'C'
#define END 'Q'


void Menu();
void Play();
void Display(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char CheckWin(char board[ROW][COL], int row, int col);
