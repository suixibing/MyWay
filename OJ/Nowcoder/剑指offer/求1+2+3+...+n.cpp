class Solution {
public:
    class AddClass
    {
    private:
        int m_sum;
    public:
        AddClass(int n = 1)
            : m_sum(n)
        {
            if (n > 1)
                m_sum += AddClass(n - 1).show();
        }
        int show()
        {
            return m_sum;
        }
    };
    int Sum_Solution(int n)
	{
        return AddClass(n).show();
    }
};