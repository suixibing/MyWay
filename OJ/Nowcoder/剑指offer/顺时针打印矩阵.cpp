class Solution {
private:
    vector< vector<int> > offset = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
public:
    vector<int> printMatrix(vector< vector<int> > matrix)
    {
        if (matrix.empty())
            return vector<int>();
        vector<int> ret;
        int x = 0, y = 0, tmpx, tmpy, flag = 0;
        int col = matrix[0].size(), row = matrix.size();
        vector< vector<int> > book(row, vector<int>(col, 0));
        while (x >= 0 && x < row && y >= 0 && y < col && book[x][y] == 0)
        {
            book[x][y] = 1;
            ret.push_back(matrix[x][y]);
            tmpx = x + offset[flag][0];
            tmpy = y + offset[flag][1];
            if (tmpx < 0 || tmpx >= row || tmpy < 0 || tmpy >= col 
                || book[tmpx][tmpy] != 0)
            {
                ++flag;
                if (flag == 4)
                    flag = 0;
            }
            x += offset[flag][0];
            y += offset[flag][1];
        }
        return ret;
    }
};