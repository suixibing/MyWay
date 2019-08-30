#include "Player.h"

char Player::m_s_book[Player::m_s_Len] = { 0 };

Player::Player()
{
	m_num = 0;
	memset(m_cardInHand, 0, sizeof(m_cardInHand));
}


Player::~Player()
{
}

bool Player::GetPoker(char key)
{
	int i;
	
	if (key < 0 || key >= m_s_Len || m_s_book[key])
	{
		return false;
	}
	Poker tmp(key % K + 1, key / K + 1);
	m_s_book[key]++;
	for (i = m_num - 1; i >= 0 && m_cardInHand[i] > tmp; i--)
	{
		m_cardInHand[i + 1] = m_cardInHand[i];
	}
	m_num++;
	m_cardInHand[i + 1] = tmp;

	return true;
}

void Player::ShowHand()
{
	for (int i = 0; i < m_num; i++)
	{
		std::cout << m_cardInHand[i] << "  ";
	}
	std::cout << std::endl;
}