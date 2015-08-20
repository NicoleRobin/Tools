/*
 * Class Name		: CReadConfig
 * Function			: Parse config
 * Date				: 2015-08-19
 * Author			: zjw
 */
#pragma once
#include <map>
#include <vector>
#include <string>

class CReadConfig
{
public:
	static CReadConfig* GetInstance(const std::string& strFile);

public:
	bool GetConfig(std::map<std::string, std::map<std::string, std::vector<std::string> > > &mapConfig);
	bool GetConfig(const std::string& strRoot, std::map<std::string, std::vector<std::string> > &mapConfig);
	bool GetConfig(const std::string& strRoot, const std::string &strKey, std::vector<std::string> &vecValues);
	~CReadConfig();
private:
	CReadConfig(const std::string strFile);
	bool ParseConfig();
	void TrimStr(std::string &str);
private:
	static CReadConfig* m_pInstance;
	std::map<std::string, std::map<std::string, std::vector<std::string> > > m_mapConfig;
	std::string m_strFile;
};

