#include"game.h"

int main()
{
	int input = -1;
	srand((unsigned int)time(NULL));
	while (input)
	{
		Menu();
		printf("请输入您要进行的操作:>");
		if (!scanf("%d", &input))
		{
			getchar();
		}
		switch (input)
		{
		case 1:
			Play();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入错误请重新输入\n");
			break;
		}
	}

	return 0;
}