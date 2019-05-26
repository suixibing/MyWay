#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define WALL '#'
#define ENEMY 'G'
#define GRASS '.'


void BomberMan_1();
void StickEquation();
void FullPermutation_1();
void FullPermutation_DFS(int *base, int step, int *book, int num);
void EquationEnum();
void EquationArr();