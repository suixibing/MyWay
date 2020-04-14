class Solution {
public:
	int cutRope(int number)
	{
        if (number == 2 || number == 3)
			return number - 1;
		vector<int> book(number + 1);
		for (int i = 1; i <= number; ++i)
		{
			book[i] = i;
			for (int j = 1; j < i; ++j)
			{
				if (j * book[i - j] > book[i])
					book[i] = j * book[i - j];
			}
		}
		return book[number];
	}
};