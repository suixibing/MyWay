class Solution {
public:
    vector<string> Permutation(string str)
    {
        if (str == "")
            return vector<string>();
        vector<string> res;
        sort(str.begin(), str.end());
        res.push_back(str);
        next_permutation(str.begin(), str.end());
        while (str != res[0])
        {
            res.push_back(str);
            next_permutation(str.begin(), str.end());
        }
        return res;
    }
};