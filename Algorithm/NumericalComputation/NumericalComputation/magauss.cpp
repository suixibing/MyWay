#include "task.h"

void show(const valarray<double>& arr, int row, int col)
{
	for (int i = 0; i < row * col; i++)
	{
		cout.width(10);
		cout << arr[i] << " ";
		if ((i + 1) % col == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}

void magauss()
{
	int i, j, k, row;
	cout << "请输入方程个数:> ";
	cin >> row;
	int col = row + 1;
	valarray<double> arr(row * col);

	cout << "请依次输入每个方程的系数:> \n";
	for (i = 0; i < row * col; i++)
	{
		cin >> arr[i];
	}
	for (k = 0; k < row; k++)
	{
		int maxi = k + k * col;
		double max = arr[maxi];
		for (i = maxi; i < row * col; i += col)
		{
			if (arr[i] > max)
			{
				max = arr[i];
				maxi = i;
			}
		}
		if (!max)
		{
			break;
		}
		valarray<double> tmp(valarray<double>(arr[slice(maxi, col - k, 1)]) / max);
		if (maxi > k + k * col)
		{
			arr[slice(maxi, col - k, 1)] = valarray<double>(arr[slice(k + k * col, col - k, 1)]);
		}
		arr[slice(k + k * col, col - k, 1)] = tmp;
		for (i = k + k * col + col; i < row * col; i += col)
		{
			arr[slice(i, col - k, 1)] = valarray<double>(arr[slice(i, col - k, 1)]) - arr[i] * tmp;
		}
	}
	valarray<double> ans(row);
	for (i = row - 1; i >= 0; i--)
	{
		ans[i] = arr[i * col + col - 1];
		for (j = i + 1; j < row; j++)
		{
			ans[i] -= arr[i * col + j] * ans[j];
		}
	}
	cout << "\nans = \n";
	for (auto i : ans)
	{
		cout.width(10);
		cout << i << "  ";
	}
	cout << endl << endl;
}