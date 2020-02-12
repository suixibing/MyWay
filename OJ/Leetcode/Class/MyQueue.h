#include "Leetcode.h"

/*
 *
 *	232. 用栈实现队列
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了67.84%的用户
 *  	内存消耗:		9.1 MB, 在所有 C++ 提交中击败了5.61%的用户
 *
 */
class MyQueue
{
private:
    stack<int> m_stack;
    stack<int> m_tmp;
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        m_stack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        while (!m_stack.empty())
        {
            m_tmp.push(m_stack.top());
            m_stack.pop();
        }
        int ret = m_tmp.top();
        m_tmp.pop();
        while (!m_tmp.empty())
        {
            m_stack.push(m_tmp.top());
            m_tmp.pop();
        }
        return ret;
    }
    
    /** Get the front element. */
    int peek() 
    {
        while (!m_stack.empty())
        {
            m_tmp.push(m_stack.top());
            m_stack.pop();
        }
        int ret = m_tmp.top();
        while (!m_tmp.empty())
        {
            m_stack.push(m_tmp.top());
            m_tmp.pop();
        }
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        return m_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */