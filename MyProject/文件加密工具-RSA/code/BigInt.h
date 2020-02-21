#pragma once
#include <string>


namespace lb
{
	class BigInt
	{
	private:
		std::string m_data;

	private:
		const std::string& dealData(std::string& data);
		const std::string add(std::string data1, std::string data2);
		const std::string sub(std::string data1, std::string data2);
		const std::string mul(std::string data1, std::string data2);
		const std::string dev(std::string data1, std::string data2);

	public:
		BigInt(long long num = 0);
		BigInt(const std::string & data);

		BigInt operator+(const BigInt & data);
		BigInt operator-(const BigInt & data);
		BigInt operator*(const BigInt & data);
		BigInt operator/(const BigInt & data);
		BigInt operator+(const std::string & data);
		BigInt operator-(const std::string & data);
		BigInt operator*(const std::string & data);
		BigInt operator/(const std::string & data);
		BigInt operator-();
		friend std::ostream& operator<<(std::ostream & os, const BigInt & data);
		friend std::istream& operator>>(std::istream & is, BigInt & data);
	};
}