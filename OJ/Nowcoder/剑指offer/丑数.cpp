class Solution {
public:
    int GetUglyNumber_Solution(int index)
    {
        if (index < 7)
            return index;
        int p2 = 0, p3 = 0, p5 = 0, res = 1;
        vector<int> book;
        book.push_back(res);
        while (book.size() < index)
        {
            res = min(book[p2] * 2, min(book[p3] * 3, book[p5] * 5));
            if (res == book[p2] * 2)
                ++p2;
            if (res == book[p3] * 3)
                ++p3;
            if (res == book[p5] * 5)
                ++p5;
            book.push_back(res);
        }
        return res;
    }
};