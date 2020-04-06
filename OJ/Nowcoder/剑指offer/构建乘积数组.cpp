class Solution {
public:
    vector<int> multiply(const vector<int>& A)
    {
        vector<int> res(A.size(), 1);
        for (int i = 0; i < A.size(); ++i)
        {
            for (int j = 0; j < A.size(); ++j)
            {
                if (i == j)
                    continue;
                res[i] *= A[j];
            }
        }
        return res;
    }
};