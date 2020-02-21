#include <ctime>
#include <fstream>
#include <iostream>
#include "rsa.h"

namespace lb
{
	Rsa::Rsa()
	{
		m_key = getRsaKey();
	}

	Rsa::Rsa(const RsaKey & key) :
		m_key(key)
	{ }

	const RsaKey& Rsa::getRsaKey()
	{
		RsaKey key;
		rsaDataType prime1, prime2;

		prime1 = getPrime();
		while ((prime2 = getPrime()) == prime1)
			continue;
		rsaDataType orla = getOrla(prime1, prime2);

		key.m_pKey = getPKey(prime1, prime2);
		key.m_eKey = getEKey(orla);
		key.m_dKey = getDKey(key.m_eKey, orla);
		return key;
	}

	bool Rsa::isPrime(rsaDataType num)
	{
		if (num <= 1)
			return false;
		for (int i = 2; i <= sqrt(num); ++i)
		{
			if (num % i == 0)
				return false;
		}
		return true;
	}

	rsaDataType Rsa::getPrime()
	{
		rsaDataType num;

		srand(static_cast<unsigned int>(time(nullptr)));
		while (true)
		{
			num = rand() % 100 + 2;
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
		return (prime1 - 1) * (prime2 - 1);
	}

	rsaDataType Rsa::getEKey(rsaDataType orla)
	{
		rsaDataType eKey;

		srand(static_cast<unsigned int>(time(nullptr)));
		while (true)
		{
			eKey = rand() % orla + 2;
			if (eKey < orla && getGcd(eKey, orla) == 1)
				break;
		}

		return eKey;
	}

	rsaDataType Rsa::getDKey(rsaDataType eKey, rsaDataType orla)
	{
		rsaDataType dKey;

		srand(static_cast<unsigned int>(time(nullptr)));
		while (true)
		{
			dKey = rand() % orla + 2;
			if ((dKey * eKey) % orla == 1 && dKey != eKey)
				break;
		}

		return dKey;
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
			if (e & 1)
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
			count = fin.gcount() / 4;
			for (int i = 0; i < count; ++i)
				bufferOut[i] = static_cast<char>(decrept(buffer[i]));
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