#include"game.h"

int main()
{
	int input = START;

	while (input)
	{
		Menu();
		printf("请选择您要进行的操作:>");
		if (!scanf("%d", &input))
		{
			input = ERROR;
			getchar();
		}
		system("cls");

		switch(input)
		{
		case END:
			printf("游戏结束！\n");
			break;
		case START:
			printf("游戏开始！\n");
			Play();
			break;
		default:
			printf("输入有误，请重新选择！\n");
			break;
		}
	}

	system("pause");
	return 0;
}