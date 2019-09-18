#include"Test.h"


//通过枚举每种情况，找出最大消灭敌人数
void BomberMan_1()
{
	int i, j, k, x, y, xx, yy, row, col, sum, max = 0, change[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
	char board[1000][1000] = { 0 };

	scanf("%d%d", &row, &col);
	for (i = 0; i < row; i++)
	{
		scanf("%s", board[i]);
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] != GRASS)
			{
				continue;
			}
			sum = 0;
			for (k = 0; k < 4; k++)
			{
				x = i;
				y = j;
				while (x + change[k][0] >= 0 && x + change[k][0] < row && y + change[k][1] >= 0 && y + change[k][1] < col)
				{
					x += change[k][0];
					y += change[k][1];
					if (board[x][y] == WALL)
					{
						break;
					}
					else if (board[x][y] == ENEMY)
					{
						sum++;
					}
				}
			}
			if (sum > max)
			{
				max = sum;
				xx = i;
				yy = j;
			}
		}
	}
	printf("将炸弹放置到(%d,%d)位置，最多可以消灭%d个敌人\n", xx, yy, max);
}


//测试数据
/*


13 13
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.###
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############


将炸弹放置到(9,9)位置，最多可以消灭8个敌人



13 13
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.#.#
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############


将炸弹放置到(1,11)位置，最多可以消灭11个敌人


*/