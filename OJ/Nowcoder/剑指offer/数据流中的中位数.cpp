class Solution {
    vector<int> m_vec;
public:
    void Insert(int num)
    {
        for (int i = 0; i < m_vec.size(); ++i)
        {
            if (num <= m_vec[i])
            {
                m_vec.insert(m_vec.begin() + i, num);
                return;
            }
        }
        m_vec.push_back(num);
    }
    double GetMedian()
    { 
        if (m_vec.size() % 2)
            return m_vec[m_vec.size() / 2];
        else
            return (m_vec[m_vec.size() / 2] + m_vec[m_vec.size() / 2 - 1]) / 2.0;
    }
};