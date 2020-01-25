#pragma once

namespace lb
{
	// 计数类,用于需要引用计数的类
	class UseCount
	{
	private:
		int *m_cnt;
	public:
		UseCount() : m_cnt(new int(1)) { }
		UseCount(const UseCount & uc) : m_cnt(uc.m_cnt) { ++(*m_cnt); }
		~UseCount() { if (--(*m_cnt) == 0) delete m_cnt; }
		int count() const { return *m_cnt; }
		bool only() const { return *m_cnt == 1; }
		bool reattach(const UseCount & uc);
		bool makeOnly();
	private:
		UseCount& operator=(const UseCount & uc) { } // 不实现,阻止直接赋值操作
	};
	bool UseCount::reattach(const UseCount & uc)
	{
		++(*uc.m_cnt);
		if (--(*m_cnt) == 0)
		{
			delete m_cnt;
			m_cnt = uc.m_cnt;
			return true;
		}
		m_cnt = uc.m_cnt;
		return false;
	}
	bool UseCount::makeOnly()
	{
		if (*m_cnt == 1)
			return false;
		--(*m_cnt);
		m_cnt = new int(1);
		return true;
	}
}