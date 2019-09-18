#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("************************************\n");
	printf("*******        0.end         *******\n");
	printf("*******        1.play        *******\n");
	printf("************************************\n");
}

void play()
{
	int target = 0;
	int guess = 0;

	target = rand() % 100 + 1;
	while (1)
	{
		printf("请输入你猜的数字(1-100):>");
		scanf("%d", &guess);
		if (guess > target)
		{
			printf("猜大了！\n\n");
		}
		else if (guess < target)
		{
			printf("猜小了！\n\n");
		}
		else
		{
			printf("恭喜你，猜对了！！\n\n");
			break;
		}
	}
}

int main()
{
	int input;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请输入你的选择:>");
		scanf("%d", &input);

		switch (input)
		{
		case 0:
			printf("游戏结束！\n");
			break;
		case 1:
			play();
			break;
		default:
			printf("选择错误，请重新输入！\n");
			break;
		}
	} while (input != 0);

	system("pause");
	return 0;
}