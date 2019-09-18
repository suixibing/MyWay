#include"Test.h"

#define NUM 10

void EquationArr()
{
	int i, flag, count = 0, a[10] = { 0 }, book[10] = { 0 };

	for (a[0] = 1; a[0] < NUM; a[0]++)
	{
		for (a[1] = 1; a[1] < NUM; a[1]++)
		{
			for (a[2] = 1; a[2] < NUM; a[2]++)
			{
				for (a[3] = 1; a[3] < NUM; a[3]++)
				{
					for (a[4] = 1; a[4] < NUM; a[4]++)
					{
						for (a[5] = 1; a[5] < NUM; a[5]++)
						{
							for (a[6] = 1; a[6] < NUM; a[6]++)
							{
								for (a[7] = 1; a[7] < NUM; a[7]++)
								{
									for (a[8] = 1; a[8] < NUM; a[8]++)
									{
										for (i = 0; i < NUM; i++)
										{
											book[i] = 0;
										}
										for (i = 0; i < NUM - 1; i++)
										{
											book[a[i]] = 1;
										}
										for (i = 1, flag = 1; i < NUM; i++)
										{
											if (book[i] == 0)
											{
												flag = 0;
											}
										}
										if (flag && 100 * a[0] + 10 * a[1] + a[2] + 100 * a[3] + 10 * a[4] + a[5] == 100 * a[6] + 10 * a[7] + a[8])
										{
											count++;
											printf("%d%d%d + %d%d%d = %d%d%d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("共有%d个\n", count / 2);
}

void EquationEnum()
{
	int a, b, c, d, e, f, g, h, i, count = 0;

	for (a = 1; a < NUM; a++)
	{
		for (b = 1; b < NUM; b++)
		{
			if (a == b)
			{
				continue;
			}
			for (c = 1; c < NUM; c++)
			{
				if (c == a || c == b)
				{
					continue;
				}
				for (d = 1; d < NUM; d++)
				{
					if (d == a || d == b || d == c)
					{
						continue;
					}
					for (e = 1; e < NUM; e++)
					{
						if (e == a || e == b || e == c || e == d)
						{
							continue;
						}
						for (f = 1; f < NUM; f++)
						{
							if (f == a || f == b || f == c || f == d || f == e)
							{
								continue;
							}
							for (g = 1; g < NUM; g++)
							{
								if (g == a || g == b || g == c || g == d || g == e || g == f)
								{
									continue;
								}
								for (h = 1; h < NUM; h++)
								{
									if (h == a || h == b || h == c || h == d || h == e || h == f || h == g)
									{
										continue;
									}
									for (i = 1; i < NUM; i++)
									{
										if (i == a || i == b || i == c || i == d || i == e || i == f || i == g || i == h)
										{
											continue;
										}
										if ((100 * a + 10 * b + c) + (100 * d + 10 * e + f) == (100 * g + 10 * h + i))
										{
											count++;
											printf("%d%d%d + %d%d%d = %d%d%d\n", a, b, c, d, e, f, g, h, i);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("共有%d个\n", count / 2);
}

int EquationDFS(int *base, int step, int *book)
{
	int i;
	static int count = 0;

	if (step == 0)
	{
		count = 0;
	}
	else if (step == NUM - 1)
	{
		if (100 * base[0] + 10 * base[1] + base[2] + 100 * base[3] + 10 * base[4] + base[5] == 100 * base[6] + 10 * base[7] + base[8])
		{
			count++;
			printf("%d%d%d + %d%d%d = %d%d%d\n", base[0], base[1], base[2], base[3], base[4], base[5], base[6], base[7], base[8]);
		}
		return 0;
	}
	for (i = 1; i < NUM; i++)
	{
		if (book[i] == 0)
		{
			book[i] = 1;
			base[step] = i;
			EquationDFS(base, step + 1, book);
			book[i] = 0;
		}
	}

	return count / 2;
}