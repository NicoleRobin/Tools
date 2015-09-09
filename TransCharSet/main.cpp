#include "ReadConfig.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string strFile = "test.conf";
	map<string, map<string, vector<string> > > mapConfig;
	CReadConfig *pConfig = CReadConfig::GetInstance(strFile);
	pConfig->GetConfig(mapConfig);

	map<string, map<string, vector<string> > >::iterator itX;
	for (itX = mapConfig.begin(); itX != mapConfig.end(); itX++)
	{
		cout << itX->first << endl;
		map<string, vector<string> >::iterator itY;
		for (itY = itX->second.begin(); itY != itX->second.end(); itY++)
		{
			cout << "\t" << itY->first;
			vector<string>::iterator itZ;
			for (itZ = itY->second.begin(); itZ != itY->second.end(); itZ++)
			{
				if (itZ == itY->second.begin())
				{
					cout << "=" << *itZ;
				}
				else
				{
					cout << "," << *itZ;
				}
			}
			cout << endl;
		}
	}
	return 0;
}