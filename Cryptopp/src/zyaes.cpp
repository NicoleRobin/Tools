#include "zyaes.h"
#include <string.h>
#include <stdio.h>

CZYAes::CZYAes()
{
    byte byteKey[] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08, 0x01,0x02, 0x03,0x04,0x05,0x06,0x07,0x08, 
                0x01,0x02, 0x03,0x04,0x05,0x06,0x07,0x08, 0x01,0x02, 0x03,0x04,0x05,0x06,0x07,0x08};
    byte byteIv[] = {0x01,0x02,0x03,0x04,0x01,0x02,0x03,0x04, 0x01,0x02, 0x03,0x04,0x01,0x02,0x03,0x04};
    memcpy(m_arrByteKey, byteKey, sizeof(byte) * 32);
    memcpy(m_arrByteIv, byteIv, sizeof(byte) * 16);
	m_nKeyLen = 32;
}

CZYAes::~CZYAes()
{
}

// set key and iv
void CZYAes::SetKey(std::string strKey, std::string strIv)
{
	int nKeyLen = 0;
	int nIvLen = 0;
	memset(m_arrByteKey, 0, sizeof(byte) * 32);
    memset(m_arrByteIv, 0, sizeof(byte) * 16);
	
	if (strKey.length() >= 32)
	{
		nKeyLen = 32;
	}
	else
	{
		nKeyLen = strKey.length();
	}
	memcpy(m_arrByteKey, strKey.c_str(), sizeof(byte) * nKeyLen);
	
	if (!strIv.empty())
	{
		if (strIv.length() >= 16)
		{
			nIvLen = 16;
		}	
		else
		{
			nIvLen = strIv.length();
		}
		memcpy(m_arrByteIv, strIv.c_str(), sizeof(byte) * nIvLen);
	}
}

// encrypt
std::string CZYAes::Encrypt(const std::string &strText)
{
	std::string strCipher;
	CBC_Mode<AES>::Encryption aesEncryptor(m_arrByteKey, m_nKeyLen, m_arrByteIv);
	StringSource(strText, true, new StreamTransformationFilter(aesEncryptor, new StringSink(strCipher)));
	
	std::string strEncoded;
	StringSource s2(strCipher, true,
		new HexEncoder(
			new StringSink(strEncoded)
		) // HexEncoder
	); // StringSource
	return strEncoded;
}

// decrypt
std::string CZYAes::Decrypt(const std::string &strCipher)
{
	std::string strDecoded;
	StringSource s2(strCipher, true,
		new HexDecoder(
			new StringSink(strDecoded)
		) // HexEncoder
	); // StringSource

	std::string strText;

	try
	{
		CBC_Mode<AES>::Decryption aesEncryptor(m_arrByteKey, m_nKeyLen, m_arrByteIv);
		StringSource(strDecoded, true, new StreamTransformationFilter(aesEncryptor, new StringSink(strText)));
	}
	catch (CryptoPP::InvalidCiphertext&)
	{
		strText = "";
	}
	return strText;
}
