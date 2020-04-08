class Solution
{
    string m_str;
    map<char, int> m_book;
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        m_str += ch;
        ++m_book[ch];
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for (auto ch : m_str)
        {
            if (m_book[ch] == 1)
                return ch;
        }
        return '#';
    }

};