class Solution {
	int getBitSum(int num)
	{
		int ret = 0;
		while (num)
		{
			ret += num % 10;
			num /= 10;
		}
		return ret;
	}
	int dfs(vector<string> &book, int threshold, int x, int y)
	{
		static const int offset[4][2] = { {1, 0}, {1, -1}, {0, 1}, {0, -1} };
		int xx, yy, cnt = 1;
		book[x][y] = '1';
		for (int i = 0; i < 4; ++i)
		{
			xx = x + offset[i][0];
			yy = y + offset[i][1];
			if (xx >= 0 && xx < book.size() && yy >= 0 && yy < book[0].size()
				&& book[xx][yy] == '0' && getBitSum(xx) + getBitSum(yy) <= threshold)
				cnt += dfs(book, threshold, xx, yy);
		}
		return cnt;
	}
public:
	int movingCount(int threshold, int rows, int cols)
	{
        if (threshold < 0)
            return 0;
		vector<string> book(rows, string(cols, '0'));
		return dfs(book, threshold, 0, 0);
	}
};