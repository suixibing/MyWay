class Solution {
	vector<string> m_book;
	const int offset[4][2] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };
	bool doHasPath(char *matrix, int x, int y, char *str)
	{
		if (*str != *(matrix + x * m_book[0].size() + y))
			return false;
		if (*str == '\0' || *(str + 1) == '\0')
			return true;
		m_book[x][y] = '1';
		for (int i = 0; i < 4; ++i)
		{
			if (x + offset[i][0] >= 0 && x + offset[i][0] < m_book.size()
				&& y + offset[i][1] >= 0 && y + offset[i][1] < m_book[0].size()
				&& m_book[x + offset[i][0]][y + offset[i][1]] == '0' 
				&& doHasPath(matrix, x + offset[i][0], y + offset[i][1], str + 1))
				return true;
		}
		m_book[x][y] = '0';
		return false;
	}
public:
	bool hasPath(char *matrix, int rows, int cols, char *str)
	{
		m_book = vector<string>(rows, string(cols, '0'));
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (doHasPath(matrix, i, j, str))
					return true;
			}
		}
		return false;
	}
};