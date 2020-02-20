#pragma once
#include <string>

namespace lb
{
	typedef long rsaDataType;

	struct RsaKey
	{
		rsaDataType m_eKey;
		rsaDataType m_dKey;
		rsaDataType m_pKey;
	};

	class Rsa
	{
	private:
		RsaKey m_key;
	public:
		Rsa();
		Rsa(RsaKey & key);

		bool isPrime(rsaDataType num);
		RsaKey getRsaKey();
		rsaDataType getPrime();
		rsaDataType getPKey(rsaDataType prime1, rsaDataType prime2);
		rsaDataType getOrla(rsaDataType prime1, rsaDataType prime2);
		rsaDataType getEKey(rsaDataType orla);
		rsaDataType getDKey(rsaDataType eKey, rsaDataType orla);
		rsaDataType getGcd(rsaDataType num1, rsaDataType num2);
		rsaDataType dealData(rsaDataType data, rsaDataType e, rsaDataType n);
		rsaDataType ecrept(rsaDataType data);
		rsaDataType ecrept(rsaDataType data, rsaDataType eKey, rsaDataType pKey);
		rsaDataType decrept(rsaDataType data);
		rsaDataType decrept(rsaDataType data, rsaDataType dKey, rsaDataType pKey);
		void ecreptFile(const std::string filename, const std::string e_filename);
		void decreptFile(const std::string e_filename, const std::string d_filename);

		void show() const;
	};
}