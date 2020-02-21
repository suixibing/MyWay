#include "BigInt.h"
#include <cctype>
#include <iostream>

namespace lb
{
	BigInt::BigInt(long long num)
	{
		int flag = 0;
		if (num < 0) // 记录num是否为负数
			flag = 1;
		while (num)
		{
			m_data.insert(0, 1, '0' + num % 10); // 从低位开始插入数字
			num /= 10;
		}
		if (flag)
			m_data.insert(0, 1, '-'); // 将负号插入到数字的开头
	}

	BigInt::BigInt(const std::string & data)
	{
		std::string str = data;
		m_data = dealData(str); // 将输入的字符串处理为可用的大数
	}

	const std::string& BigInt::dealData(std::string& data)
	{
		int start = 0, end = 0, flag = 0;
		while (data[start] == '+' || data[start] == '-' 
			|| data[start] == '0') // 当以+-0开头时，先掠过这些信息
		{
			if (data[start] == '-') // 如果存在负号，标记读取了一个负数
				flag = 1;
			++start;
		}
		end = start; // 从首个数字开始向后，统计连续的数字出现的个数
		while (end < data.size() && isdigit(data[end]))
			++end;
		data = data.substr(start, end - start); // 截取连续的数字
		if (flag) // 当为负数时，将负号插入到数字的开头
			data.insert(0, 1, '-');
		return data;
	}

	const std::string BigInt::add(std::string data1, std::string data2)
	{
		// 对开始的正号进行处理
		if (data1[0] == '+')
			data1.erase(0, 1);
		if (data2[0] == '+')
			data2.erase(0, 1);

		// 对有负号的情况进行处理，变加法为减法
		if (data1[0] == '-')
			return sub(data2, data1.substr(1));
		else if (data2[0] == '-')
			return sub(data1, data2.substr(1));

		if (data1.size() < data2.size()) // 补零使两个data的大小一致
			data1.insert(0, data2.size() - data1.size(), '0');
		else
			data2.insert(0, data1.size() - data2.size(), '0');
		int step = 0;
		std::string res(data1.size(), '0');

		for (int i = static_cast<int>(data1.size()) - 1; i >= 0; --i) // 从低位向高位进行计算
		{
			res[i] = (data1[i] - '0') + (data2[i] - '0') + step; // 两数相加的临时值，是个整数
			step = res[i] / 10; // 更新进位信息
			res[i] = res[i] % 10 + '0'; // 更新当前位的结果，是个字符
		}
		if (step) // 处理可能存在的未处理的进位
			res.insert(0, "1");

		return res;
	}

	const std::string BigInt::sub(std::string data1, std::string data2)
	{
		// 对开始的正号进行处理
		if (data1[0] == '+')
			data1.erase(0, 1);
		if (data2[0] == '+')
			data2.erase(0, 1);

		// 对有负号的情况进行处理
		if (data2[0] == '-') // data2为负数时，变减法为加法，同时去除data2的负号
			return add(data1, data2.substr(1));
		else if (data1[0] == '-') // data1为负数时，提负号。去除data1的负号后，内部进行data1+data2
		{
			std::string res = add(data1.substr(1), data2);
			res.insert(0, 1, '-');
			return res;
		}
		if (data1.size() < data2.size() // data1小于data2时，提负号，内部进行data2-data1
			|| data1.size() == data2.size() && data1[0] < data2[0])
		{
			std::string res = sub(data2, data1);
			res.insert(0, 1, '-');
			return res;
		}

		int i;
		std::string res(data1.size(), '0');
		data2.insert(0, data1.size() - data2.size(), '0'); // 补零使两个data的大小一致

		for (i = static_cast<int>(data1.size()) - 1; i >= 0; --i) // 从低位向高位进行计算
		{
			if (data1[i] < data2[i]) // 判断是否需要借位操作
			{
				data1[i] += 10; // 借位
				--data1[i - 1];
			}
			res[i] = data1[i] - data2[i] + '0'; // 保存当前位的结果
		}
		for (i = 0; i <= res.size() && res[i] == '0'; ++i) // 统计运算结束后开头可能存在的0的个数
			continue;

		return res.substr(i); // 返回开头不带0的结果
	}

	const std::string BigInt::mul(std::string data1, std::string data2)
	{
		// 对开始的正号进行处理
		if (data1[0] == '+')
			data1.erase(0, 1);
		if (data2[0] == '+')
			data2.erase(0, 1);

		// 对有负号的情况进行处理
		if (data1[0] == '-' && data2[0] == '-') // 两个负数相乘，负负为正
		{
			data1.erase(0);
			data2.erase(0);
		}
		else if (data1[0] == '-') // 异号相乘，结果为负数
		{
			std::string res = mul(data1.substr(1), data2);
			res.insert(0, 1, '-');
			return res;
		}
		else if (data2[0] == '-') // 异号相乘，结果为负数
		{
			std::string res = mul(data1, data2.substr(1));
			res.insert(0, 1, '-');
			return res;
		}

		int i, j;
		std::string res("0");

		for (i = static_cast<int>(data1.size()) - 1; i >= 0; --i) // 使用data1中的每一位乘data2
		{
			int step = 0, curData = data1[i] - '0'; // 进位信息和用来乘data2的当前值
			std::string temp(data2.size(), '0'); // 保存每一次相乘的临时结果

			for (j = static_cast<int>(data2.size()) - 1; j >= 0; --j) // 从低位向高位进行计算
			{
				step += (data2[j] - '0') * curData; // 两数相乘的临时值，是个整数
				temp[j] = step % 10 + '0'; // 将当前位的结果保存到临时结果中
				step /= 10; // 更新进位信息
			}
			if (step) // 处理可能存在的未处理的进位
				temp.insert(0, 1, '0' + step);
			temp.append(data1.size() - 1 - i, '0'); // 为临时结果补齐结尾的0
			res = add(res, temp);
		}
		for (i = 0; i <= res.size() && res[i] == '0'; ++i) // 统计运算结束后开头可能存在的0的个数
			continue;

		return res.substr(i); // 返回开头不带0的结果
	}

	const std::string BigInt::dev(std::string data1, std::string data2)
	{
		return "";
	}

	BigInt BigInt::operator+(const BigInt & data)
	{
		return add(m_data, data.m_data);
	}

	BigInt BigInt::operator-(const BigInt & data)
	{
		return sub(m_data, data.m_data);
	}

	BigInt BigInt::operator*(const BigInt & data)
	{
		return mul(m_data, data.m_data);
	}

	BigInt BigInt::operator/(const BigInt & data)
	{
		return dev(m_data, data.m_data);
	}

	BigInt BigInt::operator+(const std::string & data)
	{
		return add(m_data, data);
	}

	BigInt BigInt::operator-(const std::string & data)
	{
		return sub(m_data, data);
	}

	BigInt BigInt::operator*(const std::string & data)
	{
		return mul(m_data, data);
	}

	BigInt BigInt::operator/(const std::string & data)
	{
		return dev(m_data, data);
	}

	BigInt BigInt::operator-() // 取反运算符重载
	{
		BigInt res(m_data); // 创建副本

		if (res.m_data[0] == '-') // 删去符号
			res.m_data.erase(0, 1);
		else if (res.m_data[0] == '+') // 将正号改为符号
			res.m_data[0] = '-';
		else // 将负号插入到数字的开头
			res.m_data.insert(0, 1, '-');
		
		return res;
	}

	std::ostream& operator<<(std::ostream & os, const BigInt & data) // 输出运算符重载
	{
		os << data.m_data;
		return os;
	}

	std::istream& operator>>(std::istream & is, BigInt & data) // 输入运算符重载
	{
		is >> data.m_data;
		data.dealData(data.m_data);
		return is;
	}
}