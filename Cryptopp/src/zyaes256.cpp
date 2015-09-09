//*****************************************************************************
//@FileName	: zyaes256.cpp
//@Version	: v1.0.0
//@Author	: zjw
//@Date		: 2015-09-08
//*****************************************************************************
#include "zyaes.h"
#include "zyaes256.h"
using namespace std;

string Encrypt(const string &strText, const string &strKey/* = "" */)
{
	std::string strCipher;
	int nLen = 0;
	CZYAes aes;
	
	if (!strKey.empty())
	{
		aes.SetKey(strKey, "");
	}
	strCipher = aes.Encrypt(strText);
	return strCipher;
}

string Decrypt(const string &strCipher, const string &strKey/* = "" */)
{
	std::string strText;
	int nLen = 0;
	CZYAes aes;
	
	if (!strKey.empty())
	{
		aes.SetKey(strKey, "");
	}
	strText = aes.Decrypt(strCipher);
	return strText;
}
