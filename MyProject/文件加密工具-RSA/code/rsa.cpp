#include <ctime>
#include <fstream>
#include <iostream>
#include "rsa.h"
#include "BigInt.h"

namespace lb
{
	Rsa::Rsa()
	{
		m_key = getRsaKey();
	}

	Rsa::Rsa(const RsaKey & key) :
		m_key(key)
	{ }

	rsaDataType Rsa::getRandom()
	{
		if (typeid(rsaDataType).name() == typeid(BigInt).name())
			return BigInt::getRandom(10);
		srand(static_cast<unsigned int>(time(nullptr)));
		return rand() % 100 + 2;
	}

	RsaKey Rsa::getRsaKey()
	{
		RsaKey key;
		rsaDataType prime1, prime2;

		prime1 = getPrime();
		if (DEBUG)
			std::cout << "prime1: " << prime1 << std::endl;
		while ((prime2 = getPrime()) == prime1)
			continue;
		if (DEBUG)
			std::cout << "prime2: " << prime2 << std::endl;
		rsaDataType orla = getOrla(prime1, prime2);
		if (DEBUG)
			std::cout << "orla: " << orla << std::endl;

		key.m_pKey = getPKey(prime1, prime2);
		if (DEBUG)
			std::cout << "key.m_pKey: " << key.m_pKey << std::endl;
		key.m_eKey = getEKey(orla);
		if (DEBUG)
			std::cout << "key.m_eKey: " << key.m_eKey << std::endl;
		key.m_dKey = getDKey(key.m_eKey, orla);
		if (DEBUG)
			std::cout << "key.m_dKey: " << key.m_dKey << std::endl;
		return key;
	}

	bool Rsa::isPrime(rsaDataType num)
	{
		if (num <= rsaDataType(1))
			return false;
		for (int i = 2; i <= sqrt((long long)num); ++i)
		//for (rsaDataType i = 2; i < num; ++i)
		{
			if (num % rsaDataType(i) == rsaDataType(0LL))
				return false;
		}
		return true;
	}

	rsaDataType Rsa::getPrime()
	{
		rsaDataType num;
		while (true)
		{
			num = getRandom();
			if (isPrime(num))
				break;
		}
		return num;
	}

	rsaDataType Rsa::getPKey(rsaDataType prime1, rsaDataType prime2)
	{
		return prime1 * prime2;
	}

	rsaDataType Rsa::getOrla(rsaDataType prime1, rsaDataType prime2)
	{
		return (prime1 - rsaDataType(1)) * (prime2 - rsaDataType(1));
	}

	rsaDataType Rsa::getEKey(rsaDataType orla)
	{
		rsaDataType eKey;

		srand(static_cast<unsigned int>(time(nullptr)));
		while (true)
		{
			eKey = rsaDataType(rand()) % orla + rsaDataType(2);
			if (eKey < orla && getGcd(eKey, orla) == rsaDataType(1))
				break;
		}

		return eKey;
	}

	rsaDataType Rsa::getDKey(rsaDataType eKey, rsaDataType orla)
	{
		rsaDataType dKey, tmp;

		extendGcd(eKey, orla, dKey, tmp);
		
		return (dKey % orla + orla) % orla;
	}

	rsaDataType Rsa::extendGcd(rsaDataType a, rsaDataType b, rsaDataType & x, rsaDataType & y)
	{
		if (b == 0)
		{
			x = 1;
			y = 0LL;
			return a;
		}
		rsaDataType gcd = extendGcd(b, a % b, x, y);
		rsaDataType x1 = x, y1 = y;
		x = y1;
		y = x1 - a / b * y1;
		return gcd;
	}

	rsaDataType Rsa::getGcd(rsaDataType num1, rsaDataType num2)
	{
		rsaDataType gcd;

		while (gcd = num1 % num2)
		{
			num1 = num2;
			num2 = gcd;
		}

		return num2;
	}

	rsaDataType Rsa::dealData(rsaDataType data, rsaDataType e, rsaDataType n)
	{
		rsaDataType Ai = data;
		rsaDataType msg_e = 1;

		while (e)
		{
			if (e % rsaDataType(2) == rsaDataType(1))
				msg_e = (msg_e * (Ai % n)) % n;
			Ai = (Ai % n) * (Ai % n);
			e >>= 1;
		}

		return msg_e;
	}

	rsaDataType Rsa::ecrept(rsaDataType data)
	{
		return dealData(data, m_key.m_eKey, m_key.m_pKey);
	}

	rsaDataType Rsa::ecrept(rsaDataType data, rsaDataType eKey, rsaDataType pKey)
	{
		return dealData(data, eKey, pKey);
	}

	rsaDataType Rsa::decrept(rsaDataType data)
	{
		return dealData(data, m_key.m_dKey, m_key.m_pKey);
	}

	rsaDataType Rsa::decrept(rsaDataType data, rsaDataType dKey, rsaDataType pKey)
	{
		return dealData(data, dKey, pKey);
	}

	bool Rsa::ecreptFile(const std::string filename, const std::string e_filename)
	{
		std::ifstream fin(filename, std::ifstream::binary);
		if (!fin.is_open())
		{
			std::cerr << "文件打开失败: " << filename << std::endl;
			return false;
		}
		std::streamsize count;
		std::ofstream fout(e_filename, std::ifstream::binary);
		char *buffer = new char[BUFFERSIZE];
		rsaDataType *bufferOut = new rsaDataType[BUFFERSIZE];

		while (!fin.eof())
		{
			fin.read(buffer, BUFFERSIZE);
			count = fin.gcount();
			for (int i = 0; i < count; ++i)
				bufferOut[i] = ecrept(static_cast<rsaDataType>(buffer[i]));
			fout.write(reinterpret_cast<char *>(bufferOut), count * sizeof(rsaDataType));
		}

		fin.close();
		fout.close();
		delete[] buffer;
		delete[] bufferOut;
		return true;
	}

	bool Rsa::decreptFile(const std::string e_filename, const std::string d_filename)
	{
		std::ifstream fin(e_filename, std::ifstream::binary);
		if (!fin.is_open())
		{
			std::cerr << "文件打开失败: " << e_filename << std::endl;
			return false;
		}
		std::streamsize count;
		std::ofstream fout(d_filename, std::ifstream::binary);
		char *bufferOut = new char[BUFFERSIZE];
		rsaDataType *buffer = new rsaDataType[BUFFERSIZE];
		while (!fin.eof())
		{
			fin.read(reinterpret_cast<char *>(buffer), BUFFERSIZE * sizeof(rsaDataType));
			count = fin.gcount() / sizeof(rsaDataType);
			for (int i = 0; i < count; ++i)
				bufferOut[i] = decrept(buffer[i]);
			fout.write(bufferOut, count);
		}

		fin.close();
		fout.close();
		delete[] buffer;
		delete[] bufferOut;
		return true;
	}

	void Rsa::show() const
	{
		std::cout << "公钥: " << m_key.m_eKey << ',' << m_key.m_pKey << std::endl;
		std::cout << "私钥: " << m_key.m_dKey << ',' << m_key.m_pKey << std::endl;
	}
}