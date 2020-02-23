#include "BigInt.h"
#include <cctype>
#include <ctime>
#include <utility>
#include <iostream>
#include <random>

namespace lb
{
	BigInt::BigInt(long long num)
	{
		int flag = 0;
		if (num < 0) // 记录num是否为负数
		{
			num /= -1;
			flag = 1;
		}
		while (num)
		{
			m_data.insert(0, 1, '0' + num % 10); // 从低位开始插入数字
			num /= 10;
		}
		if (flag && m_data.size() > 0)
			m_data.insert(0, 1, '-'); // 将负号插入到数字的开头
		else if (m_data.size() == 0) // 当没有读到数字时，默认为0
			m_data = "0";
	}

	BigInt::BigInt(const char* data)
		: BigInt(std::string(data))
	{ }

	BigInt::BigInt(const std::string & data)
		: m_data(data)
	{
		dealData(m_data); // 将输入的字符串处理为可用的大数
	}

	BigInt BigInt::getRandom(size_t n)
	{
		std::mt19937 rng;
		rng.seed(std::random_device()());
		std::uniform_int_distribution<std::mt19937::result_type> dist(0, BigInt("1") << BigInt(n));
		return dist(rng);
	}

	std::string& BigInt::dealData(std::string& data)
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
		if (flag && data.size() > 0) // 当为负数时，将负号插入到数字的开头
			data.insert(0, 1, '-');
		else if (data.size() == 0) // 当没有读到数据时，默认为0
			data = "0";
		return data;
	}
	// 必然是两正数相加
	std::string BigInt::add(std::string data1, std::string data2)
	{
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
	// 必然是大数减小数
	std::string BigInt::sub(std::string data1, std::string data2)
	{
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
	// 必然是两正数相乘
	std::string BigInt::mul(std::string data1, std::string data2)
	{
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
	// 必然是两正数相除
	std::pair<std::string, std::string> BigInt::dev(std::string data1, std::string data2)
	{
		if (less(data1, data2))
			return make_pair("0", data1);

		std::string ret1, ret2(data1);
		int i, diffNum = data1.size() - data2.size();
		data2.append(diffNum, '0');
		for (i = 0; i <= diffNum; ++i)
		{
			char ch = '0';
			while (less(data2, ret2) || equal(data2, ret2))
			{
				ret2 = sub(ret2, data2);
				++ch;
			}
			ret1.append(1, ch);
			data2.pop_back();
		}
		for (i = 0; i <= ret1.size() && ret1[i] == '0'; ++i) // 统计运算结束后开头可能存在的0的个数
			continue;

		return make_pair(ret1.substr(i), ret2); // 返回开头不带0的结果
	}
	// 必然是正数求非负整次数幂
	std::string BigInt::pow(std::string data, std::string n)
	{
		if (n == "0")
			return "1";
		if (n == "1")
			return data;
		if (BigInt(n) % BigInt(2) == "0")
			return pow(mul(data, data), dev(n, "2").first);
		return mul(pow(mul(data, data), dev(n, "2").first), data);
	}
	BigInt BigInt::pow(BigInt n)
	{
		if (n < "0")
			throw "不支持求负次数幂";
		int flag = 0;
		if (m_data[0] == '-' && n % BigInt(2) == BigInt(1))
			flag = 1;
		std::string res = pow(m_data, n.m_data);
		if (flag)
			res.insert(0, 1, '-');
		return res;
	}

	// 判断BigInt大小关系的私有函数
	bool BigInt::less(const std::string & data1, const std::string & data2)
	{
		if (data1[0] == '-' && data2[0] == '-')
			return data1 > data2;
		if (data1[0] == '-')
			return true;
		if (data2[0] == '-')
			return false;
		return data1.size() < data2.size() || data1.size() == data2.size() && data1 < data2;
	}
	bool BigInt::equal(const std::string & data1, const std::string & data2)
	{
		return data1 == data2;
	}

	// 取反运算符重载
	BigInt BigInt::operator-()
	{
		BigInt res(m_data); // 创建副本

		if (m_data == "0")
			return res;
		if (res.m_data[0] == '-') // 删去符号
			res.m_data.erase(0, 1);
		else if (res.m_data[0] == '+') // 将正号改为符号
			res.m_data[0] = '-';
		else // 将负号插入到数字的开头
			res.m_data.insert(0, 1, '-');

		return res;
	}
	BigInt BigInt::operator++()
	{
		return *this += 1;
	}
	BigInt BigInt::operator++(int)
	{
		BigInt res(*this);
		*this += 1;
		return res;
	}
	BigInt BigInt::operator--()
	{
		return *this -= 1;
	}
	BigInt BigInt::operator--(int)
	{
		BigInt res(*this);
		*this -= 1;
		return res;
	}
	BigInt::operator long long()
	{
		if (BigInt(LLONG_MAX) < *this)
			return BigInt(LLONG_MAX);
		if (BigInt(LLONG_MIN) > *this)
			return BigInt(LLONG_MIN);

		int i = 0, flag = 0;
		long long res = 0;
		if (m_data[i] == '-')
		{
			++i;
			flag = 1;
		}
		for (; i < m_data.size(); ++i)
			res = res * 10 + m_data[i] - '0';
		if (flag)
			res *= -1;
		return res;
	}
	BigInt::operator std::string()
	{
		return m_data;
	}

	// BigInt与BigInt的加,减,乘,除,模,左移,右移运算
	BigInt BigInt::operator+(BigInt data)
	{
		// 当两个负数相加时，提负号，进行正数的加法运算
		if (m_data[0] == '-' && data.m_data[0] == '-')
		{
			std::string ret = add(m_data.substr(1), data.m_data.substr(1));
			ret.insert(0, "-");
			return ret;
		}

		// 当有一个负数时，转换为减法运算
		if (m_data[0] == '-')
			return data - m_data.substr(1);
		if (data.m_data[0] == '-')
			return *this - data.m_data.substr(1);

		// 正常进行两个正数的加法
		return BigInt(add(m_data, data.m_data));
	}
	BigInt BigInt::operator-(BigInt data)
	{
		// data1,data2都为负数时，改为计算data2-data1
		// 这里不直接调用sub，要再判断data2-data1是否小数减大数
		if (m_data[0] == '-' && data.m_data[0] == '-')
			return BigInt(data.m_data.substr(1)) - BigInt(m_data.substr(1));
		
		// data2为负数时，去除data2的负号后，减法变加法
		if (data.m_data[0] == '-')
			return add(m_data, data.m_data.substr(1));

		// data1为负数时，提负号。去除data1的负号后，内部进行data1+data2
		if (m_data[0] == '-')
		{
			BigInt res = add(m_data.substr(1), data.m_data);
			return -res;
		}

		// data1小于data2时，提负号，内部进行data2-data1
		if (m_data.size() == data.m_data.size() && m_data[0] < data.m_data[0]
			|| m_data.size() < data.m_data.size())
		{
			BigInt res = sub(data.m_data, m_data);
			return -res;
		}

		// data1大于data2时，正常计算data1-data2
		return sub(m_data, data.m_data);
	}
	BigInt BigInt::operator*(BigInt data)
	{
		// 两个负数相乘，负负为正
		if (m_data[0] == '-' && data.m_data[0] == '-')
			return mul(m_data.substr(1), data.m_data.substr(1));

		// 异号相乘，结果为负数
		if (m_data[0] == '-')
		{
			BigInt res = mul(m_data.substr(1), data.m_data);
			return -res;
		}
		if (data.m_data[0] == '-')
		{
			BigInt res = mul(m_data, data.m_data.substr(1));
			return -res;
		}

		// 正常进行两个正数的乘法
		return mul(m_data, data.m_data);
	}
	BigInt BigInt::operator/(BigInt data)
	{
		// 判断除数是否为0
		if (data.m_data == "" || data.m_data == "0")
			throw "error C2124: 被零除或对零求模";

		// 两个负数相除，负负为正
		if (m_data[0] == '-' && data.m_data[0] == '-')
			return dev(m_data.substr(1), data.m_data.substr(1)).first;

		// 异号相除，结果为负数
		if (m_data[0] == '-')
		{
			BigInt res = dev(m_data.substr(1), data.m_data).first;
			return -res;
		}
		if (data.m_data[0] == '-')
		{
			BigInt res = dev(m_data, data.m_data.substr(1)).first;
			return -res;
		}
		// 当被除数大于除数时，正常计算data1/data2
		return dev(m_data, data.m_data).first;
	}
	BigInt BigInt::operator%(BigInt data)
	{
		// 判断除数是否为0
		if (data.m_data == "" || data.m_data == "0")
			throw "error C2124: 被零除或对零求模";

		// 两个负数相除，负负为正
		if (m_data[0] == '-' && data.m_data[0] == '-')
			return dev(m_data.substr(1), data.m_data.substr(1)).second;

		// 异号相除，结果为负数
		if (m_data[0] == '-')
		{
			BigInt res = dev(m_data.substr(1), data.m_data).second;
			return -res;
		}
		if (data.m_data[0] == '-')
		{
			BigInt res = dev(m_data, data.m_data.substr(1)).second;
			return -res;
		}

		// 当被除数大于除数时，正常计算data1%data2
		return dev(m_data, data.m_data).second;
	}
	BigInt BigInt::operator<<(BigInt data)
	{
		// 左移负数次表示右移其绝对值次
		if (data < "0")
			return *this >> -data;
		return *this * pow("2", data.m_data);

	}
	BigInt BigInt::operator>>(BigInt data)
	{
		// 右移负数次表示左移其绝对值次
		if (data < "0")
			return *this << -data;
		return *this / pow("2", data.m_data);
	}
	BigInt BigInt::operator+=(BigInt data)
	{
		*this = *this + data;
		return *this;
	}
	BigInt BigInt::operator-=(BigInt data)
	{
		*this = *this - data;
		return *this;
	}
	BigInt BigInt::operator*=(BigInt data)
	{
		*this = *this * data;
		return *this;
	}
	BigInt BigInt::operator/=(BigInt data)
	{
		*this = *this / data;
		return *this;
	}
	BigInt BigInt::operator%=(BigInt data)
	{
		*this = *this % data;
		return *this;
	}
	BigInt BigInt::operator<<=(BigInt data)
	{
		*this = *this << data;
		return *this;
	}
	BigInt BigInt::operator>>=(BigInt data)
	{
		*this = *this >> data;
		return *this;
	}

	// string类型与BigInt的加,减,乘,除,模,左移,右移运算
	BigInt operator+(std::string data1, BigInt data2)
	{
		return BigInt(data1) + data2;
	}
	BigInt operator-(std::string data1, BigInt data2)
	{
		return BigInt(data1) - data2;
	}
	BigInt operator*(std::string data1, BigInt data2)
	{
		return BigInt(data1) * data2;
	}
	BigInt operator/(std::string data1, BigInt data2)
	{
		return BigInt(data1) / data2;
	}
	BigInt operator%(std::string data1, BigInt data2)
	{
		return BigInt(data1) % data2;
	}
	BigInt operator<<(std::string data1, BigInt data2)
	{
		return BigInt(data1) << data2;
	}
	BigInt operator>>(std::string data1, BigInt data2)
	{
		return BigInt(data1) >> data2;
	}

	// 整型与BigInt的加,减,乘,除,模,左移,右移运算
	BigInt operator+(long long data1, BigInt data2)
	{
		return BigInt(data1) + data2;
	}
	BigInt operator-(long long data1, BigInt data2)
	{
		return BigInt(data1) - data2;
	}
	BigInt operator*(long long data1, BigInt data2)
	{
		return BigInt(data1) * data2;
	}
	BigInt operator/(long long data1, BigInt data2)
	{
		return BigInt(data1) / data2;
	}
	BigInt operator%(long long data1, BigInt data2)
	{
		return BigInt(data1) % data2;
	}
	BigInt operator<<(long long data1, BigInt data2)
	{
		return BigInt(data1) << data2;
	}
	BigInt operator>>(long long data1, BigInt data2)
	{
		return BigInt(data1) >> data2;
	}

	// 关系运算符重载
	bool BigInt::operator<(const BigInt & data)
	{
		return less(m_data, data.m_data);
	}
	bool BigInt::operator<=(const BigInt & data)
	{
		return less(m_data, data.m_data) || equal(m_data, data.m_data);
	}
	bool BigInt::operator>(const BigInt & data)
	{
		return less(data.m_data, m_data);
	}
	bool BigInt::operator>=(const BigInt & data)
	{
		return less(data.m_data, m_data) || equal(m_data, data.m_data);
	}
	bool BigInt::operator==(const BigInt & data)
	{
		return equal(m_data, data.m_data);
	}
	bool BigInt::operator!=(const BigInt & data)
	{
		return !equal(m_data, data.m_data);
	}

	bool operator<(long long data1, const BigInt & data2)
	{
		return BigInt(data1) < data2;
	}
	bool operator<=(long long data1, const BigInt & data2)
	{
		return BigInt(data1) <= data2;
	}
	bool operator>(long long data1, const BigInt & data2)
	{
		return BigInt(data1) < data2;
	}
	bool operator>=(long long data1, const BigInt & data2)
	{
		return BigInt(data1) >= data2;
	}
	bool operator==(long long data1, const BigInt & data2)
	{
		return BigInt(data1) == data2;
	}
	bool operator!=(long long data1, const BigInt & data2)
	{
		return BigInt(data1) != data2;
	}

	// 输出运算符重载
	std::ostream& operator<<(std::ostream & os, const BigInt & data)
	{
		os << data.m_data;
		return os;
	}
	// 输入运算符重载
	std::istream& operator>>(std::istream & is, BigInt & data) 
	{
		is >> data.m_data;
		data.dealData(data.m_data);
		return is;
	}
}