#include <ctime>
#include <fstream>
#include <iostream>
#include "rsa.h"

namespace lb
{
	Rsa::Rsa()
	{
		rsaDataType prime1, prime2;
		prime1 = getPrime();
		while ((prime2 = getPrime()) == prime1)
			continue;
		rsaDataType orla = getOrla(prime1, prime2);

		m_key.m_pKey = getPKey(prime1, prime2);
		m_key.m_eKey = getEKey(orla);
		m_key.m_dKey = getDKey(m_key.m_eKey, orla);
	}
	Rsa::Rsa(RsaKey & key) :
		m_key(key)
	{ }
	RsaKey Rsa::getRsaKey()
	{
		return m_key;
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
	void Rsa::ecreptFile(const std::string filename, const std::string e_filename)
	{
		wchar_t wch;
		rsaDataType data;
		std::wifstream filein;
		std::wofstream fileout;

		filein.open(filename);
		fileout.open(e_filename);
		while (filein.get(wch))
		{
			data = ecrept(static_cast<rsaDataType>(wch));
			fileout << data << ' ';
		}
		filein.close();
		fileout.close();
	}
	void Rsa::decreptFile(const std::string e_filename, const std::string d_filename)
	{
		wchar_t wch;
		rsaDataType data;
		std::wifstream filein;
		std::wofstream fileout;
		
		filein.open(e_filename);
		fileout.open(d_filename);
		while (filein >> data)
		{
			wch = decrept(data);
			fileout << wch;
		}
		filein.close();
		fileout.close();
	}

	void Rsa::show() const
	{
		std::cout << "¹«Ô¿: " << m_key.m_eKey << ',' << m_key.m_pKey << std::endl;
		std::cout << "Ë½Ô¿: " << m_key.m_dKey << ',' << m_key.m_pKey << std::endl;
	}
}