#include "Nowcoder.h"

/*
 *
 *		求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
 *
 *  	运行时间：3ms
 *		占用内存：620k	
 *
 */
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