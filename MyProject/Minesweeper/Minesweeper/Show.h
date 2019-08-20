#pragma once

#ifndef _SHOW_H_

#define _SHOW_H_

#define ARROW_UP    0xE048
#define ARROW_DOWN  0xE050
#define ARROW_LEFT  0xE04B
#define ARROW_RIGHT 0xE04D

#define ENTER 13

void WelcomeContinue();
void WelcomeNewGame();
void WelcomeSet();
void WelcomeExit();

void SetPrimary();
void SetIntermediate();
void SetExpert();
void SetFree();

void DefineHeight(int* row, int* col, int* mine);
void DefineWidth(int *row, int *col, int *mine);
void DefineMine(int *row, int *col, int *mine);

int WelcomePage();

#endif // _SHOW_H_