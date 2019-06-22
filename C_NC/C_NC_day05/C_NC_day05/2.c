#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int find(int *a, int target, int left, int right)
{
	int mid;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (a[mid] < target)
		{
			left = mid + 1;
		}
		else if (a[mid] > target)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main2()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(a) / sizeof(a[0]);
	int target, output;

	printf("请输入你要查找的值:>");
	scanf("%d", &target);
	output = find(a, target, 0, n-1);
	if (output != -1) {
		printf("目标所在下标为：%d\n", output);
	}
	else
	{
		printf("目标值不存在！\n");
	}

	system("pause");
	return 0;
}