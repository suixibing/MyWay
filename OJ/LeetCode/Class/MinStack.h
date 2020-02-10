#include "LeetCode.h"

/*
 *
 *	155. 最小栈
 *
 *  	执行用时:		36 ms, 在所有 C++ 提交中击败了60.28%的用户
 *  	内存消耗:		17 MB, 在所有 C++ 提交中击败了11.57%的用户
 *
 */
class MinStack
{
private:
    stack<int> m_stack;
    stack<int> m_minVal;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) 
	{
        m_stack.push(x);
        if (m_minVal.size() > 0 && x <= m_minVal.top() || m_minVal.size() == 0)
            m_minVal.push(x);
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
    
    int getMin() 
	{
        return m_minVal.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */