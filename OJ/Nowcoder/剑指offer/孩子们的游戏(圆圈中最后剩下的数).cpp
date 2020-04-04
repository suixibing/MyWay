class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n <= 0 || m <= 0)
            return -1;
        vector<int> children(n);
        for (int i = 0; i < n; ++i)
            children[i] = i;
        int no = 0, cnt = 0;
        while (children.size() != 1)
        {
            for (cnt = 0; cnt < m - 1; ++cnt)
                no = (no + 1) % children.size();
            children.erase(children.begin() + no);
        }
        return children[0];
    }
};