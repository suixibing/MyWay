#include<ctime>
#include"Poker.h"
#include"Player.h"

using namespace std;

int GetRandom();

int main()
{
	srand((unsigned)time(NULL));
	Player p1, p2, p3;

	for (int i = 0; i < 18; i++)
	{
		while (!p1.GetPoker(GetRandom()));
		while (!p2.GetPoker(GetRandom()));
		while (!p3.GetPoker(GetRandom()));
	}
	p1.ShowHand();
	p2.ShowHand();
	p3.ShowHand();

	system("pause");
	return 0;
}

int GetRandom()
{
	return rand() % 54;
}