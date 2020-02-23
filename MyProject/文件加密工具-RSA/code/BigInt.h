#pragma once
#include <string>


namespace lb
{
	class BigInt
	{
	private:
		std::string m_data;

	private:
		std::string& dealData(std::string& data);
		std::string add(std::string data1, std::string data2);
		std::string sub(std::string data1, std::string data2);
		std::string mul(std::string data1, std::string data2);
		std::string pow(std::string data1, std::string data2);
		std::pair<std::string, std::string> dev(std::string data1, std::string data2);
		bool less(const std::string & data1, const std::string & data2);
		bool equal(const std::string & data1, const std::string & data2);

	public:
		BigInt(long long num = 0);
		BigInt(const char* data);
		BigInt(const std::string & data);

		static BigInt getRandom(size_t n);
		BigInt pow(BigInt n);

		operator long long();
		operator std::string();
		BigInt operator-();
		BigInt operator++();
		BigInt operator++(int);
		BigInt operator--();
		BigInt operator--(int);

		BigInt operator+(BigInt data);
		BigInt operator-(BigInt data);
		BigInt operator*(BigInt data);
		BigInt operator/(BigInt data);
		BigInt operator%(BigInt data);
		BigInt operator<<(BigInt data);
		BigInt operator>>(BigInt data);
		BigInt operator+=(BigInt data);
		BigInt operator-=(BigInt data);
		BigInt operator*=(BigInt data);
		BigInt operator/=(BigInt data);
		BigInt operator%=(BigInt data);
		BigInt operator<<=(BigInt data);
		BigInt operator>>=(BigInt data);

		friend BigInt operator+(std::string data1, BigInt data2);
		friend BigInt operator-(std::string data1, BigInt data2);
		friend BigInt operator*(std::string data1, BigInt data2);
		friend BigInt operator/(std::string data1, BigInt data2);
		friend BigInt operator%(std::string data1, BigInt data2);
		friend BigInt operator<<(std::string data1, BigInt data2);
		friend BigInt operator>>(std::string data1, BigInt data2);
		friend BigInt operator+(long long data1, BigInt data2);
		friend BigInt operator-(long long data1, BigInt data2);
		friend BigInt operator*(long long data1, BigInt data2);
		friend BigInt operator/(long long data1, BigInt data2);
		friend BigInt operator%(long long data1, BigInt data2);
		friend BigInt operator<<(long long data1, BigInt data2);
		friend BigInt operator>>(long long data1, BigInt data2);

		bool operator<(const BigInt & data);
		bool operator<=(const BigInt & data);
		bool operator>(const BigInt & data);
		bool operator>=(const BigInt & data);
		bool operator==(const BigInt & data);
		bool operator!=(const BigInt & data);
		friend bool operator<(long long data1, const BigInt & data2);
		friend bool operator<=(long long data, const BigInt & data2);
		friend bool operator>(long long data, const BigInt & data2);
		friend bool operator>=(long long data, const BigInt & data2);
		friend bool operator==(long long data, const BigInt & data2);
		friend bool operator!=(long long data, const BigInt & data2);

		friend std::ostream& operator<<(std::ostream & os, const BigInt & data);
		friend std::istream& operator>>(std::istream & is, BigInt & data);
	};
}