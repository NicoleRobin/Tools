#include "ReadConfig.h"
#include <fstream>
#include <cctype>
using namespace std;

CReadConfig* CReadConfig::m_pInstance = NULL;

CReadConfig::CReadConfig(const string strFile)
	: m_strFile(strFile)
{
}

CReadConfig::~CReadConfig()
{
}

CReadConfig* CReadConfig::GetInstance(const string &strFile)
{
	if (m_pInstance == NULL)
	{
		// 加锁
		if (m_pInstance == NULL)
		{
			m_pInstance = new CReadConfig(strFile);
			if (!m_pInstance->ParseConfig())
			{
				m_pInstance = NULL;
			}
		}
		// 解锁
	}

	return m_pInstance;
}

bool CReadConfig::GetConfig(std::map<std::string, std::map<std::string, std::vector<std::string> > > &mapConfig) 
{
	mapConfig = m_mapConfig;
	return true;
}
bool CReadConfig::GetConfig(const std::string& strRoot, std::map<std::string, std::vector<std::string> > &mapConfig) 
{
	return true;
}
bool CReadConfig::GetConfig(const std::string& strRoot, const std::string &strKey, std::vector<std::string> &vecValues) 
{
	return true;
}

bool CReadConfig::ParseConfig()
{
	bool bRet = true;
	ifstream fin(m_strFile);
	if (!fin.is_open())
	{
		bRet = false;
	}
	else
	{
		string strLine;
		string strRoot;
		map<string, vector<string> > mapRoot;
		while (getline(fin, strLine))
		{
			TrimStr(strLine);
			if (strLine.empty() || strLine[0] == '#')
			{ // 空行、注释，跳过
				continue;
			}
			if (strLine[0] == '[' && strLine[strLine.length() - 1] == ']')
			{ // 开始一个标签
				if (!strRoot.empty())
				{
					m_mapConfig.insert(make_pair(strRoot, mapRoot));
					mapRoot.clear();
				}
				strRoot = strLine.substr(1, strLine.length() - 2);
				TrimStr(strRoot);
				continue;
			}

			int nPos = strLine.find_first_of('=');
			string strKey = strLine.substr(0, nPos - 0);
			string strValue = strLine.substr(nPos + 1, strLine.length() - nPos - 1);
			TrimStr(strKey);
			TrimStr(strValue);
			vector<string> vecValue;
			while (!strValue.empty())
			{
				nPos = strValue.find_first_of(',');
				vecValue.push_back(strValue.substr(0, nPos - 0));
				if (nPos == string::npos)
				{
					break;
				}
				strValue = strValue.substr(nPos + 1, strValue.length() - nPos - 1);
			}
			mapRoot.insert(make_pair(strKey, vecValue));
		}
		m_mapConfig.insert(make_pair(strRoot, mapRoot));
	}
	return bRet;
}

void CReadConfig::TrimStr(string &str)
{
	if (str.empty())
	{
		return;
	}
	unsigned int i = 0;
	while (i < str.length())
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			i++;
		}
		else
		{
			break;
		}
	}
	str.erase(0, i - 0);

	i = str.length() - 1;
	while (i >= 0)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			i--;
		}
		else
		{
			break;
		}
	}
	str.erase(i + 1, str.length() - i);
}