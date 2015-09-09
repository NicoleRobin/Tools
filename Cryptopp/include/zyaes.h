//*****************************************************************************
//@File Name	: zyaes.h: the interface of crypto++ library
//@Version		: V1.0.0
//@Author		: zjw
//@Date			: 2015-09-08
//*****************************************************************************

#ifndef __ZYAES_H__
#define __ZYAES_H__

#include <string>
#include "aes.h"
#include "default.h"
#include "filters.h"
#include "modes.h"
#include "hex.h"

using namespace CryptoPP;
//@Description
//This class encapsulate the aes library's encryption method and decryption method.
class CZYAes
{
public:
	CZYAes();
	virtual ~CZYAes();

public:
	// encrypt plainText
	std::string Encrypt(const std::string &strText);
	// decrypt plainText
	std::string Decrypt(const std::string &strText);
	
	void SetKey(std::string strKey, std::string strIv);
private:
	byte m_arrByteKey[32];
	byte m_arrByteIv[16];
	int m_nKeyLen;
};

//@Usage Start
//CZYAes aes;
//string strCipher = aes.Encrypt(strText);
//string strText = aes.Encrypt(strCipher);
//@Usage End

#endif // __ZYAES_H__
