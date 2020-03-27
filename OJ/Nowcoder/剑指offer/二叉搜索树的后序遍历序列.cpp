class Solution {
public:
    bool judge(vector<int> &sequence, int front, int tail)
    {
        if (front >= tail)
            return true;
        int pos = -1, mid = sequence[tail--];
        for (int i = front; i < tail; ++i)
        {
            if (pos == -1 && sequence[i] > mid)
                pos = i;
            else if (pos >= 0 && sequence[i] < mid)
                return false;
        }
        return judge(sequence, front, pos - 1) && judge(sequence, pos, tail);
    }
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.empty())
            return false;
        return judge(sequence, 0, sequence.size() - 1);
    }
};