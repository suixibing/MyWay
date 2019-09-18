#pragma once
#include<iostream>
#include"Poker.h"

class Player
{
private:
	static const int m_s_Len = 54;
	static char m_s_book[m_s_Len];
	Poker m_cardInHand[20];
	char m_num;
public:
	Player();
	~Player();
	bool GetPoker(char key);
	void ShowHand();
};

