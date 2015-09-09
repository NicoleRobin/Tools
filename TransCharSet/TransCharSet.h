/*
 * Class Name		: CTransCharSet
 * Function			: Transform charset
 * Date				: 2015-09-08
 * Author			: zjw
 */
#pragma once
#include <string>
#include <map>
#include <iconv.h>

union UNCharSet
{
	UTF_8,
	GBK
};

class CTransCharSet
{
public:
	CTransCharSet();
	virtual ~CTransCharSet();
	
public:
	int TransToUTF8(std::string &strCol, UNCharSet charset = GBK);
	int TransToGBK(std::string &strCol, UNCharSet charset = UTF_8);

private:
};