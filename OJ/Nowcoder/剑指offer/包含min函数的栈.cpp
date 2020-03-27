class Solution {
private
    stackint m_stack;
    stackint m_minVal;
public
    void push(int value)
    {
        m_stack.push(value);
        if (m_minVal.empty()  value = m_minVal.top())
            m_minVal.push(value);
    }
    void pop()
    {
        if (m_stack.top() == m_minVal.top())
            m_minVal.pop();
        m_stack.pop();
    }
    int top()
    {
        return m_stack.top();
    }
    int min()
    {
        return m_minVal.top();
    }
};