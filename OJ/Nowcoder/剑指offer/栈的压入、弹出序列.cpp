class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV)
    {
        map<int, int> book;
        stack<int> sta;
        int i = 0, j = 0;
        sta.push(pushV[i++]);
        while (i <= pushV.size() && j < popV.size())
        {
            if (i < pushV.size() && book.find(popV[j]) == book.end())
            {
                book[pushV[i]] = 1;
                sta.push(pushV[i++]);
            }
            else if (sta.top() != popV[j])
                return false;
            else
            {
                ++j;
                sta.pop();
            }
        }
        return true;
    }
};