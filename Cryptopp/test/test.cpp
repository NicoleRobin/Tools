#include <iostream>
#include <string>
#include <sstream>
//#include "aes.h"
#include "zyaes256.h"

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Please input like this:test cipher" << endl;
        return 0;
    }
    string strText = argv[1];
    string strCipher;

    strCipher = Encrypt(strText.c_str());
	cout << strCipher << endl;
/*
	char ch;
	string strTmp;
    for (int i = 0; i < strCipher.length(); i++)
    {
        cout << hex << static_cast<int>(static_cast<unsigned char>(strCipher[i])) << " ";
	    stringstream sInOut(strCipher);
		sInOut >> hex >> ch;
		strTmp.push_back(ch);
    }
	cout << strTmp;
    cout << endl;
*/
    strText = Decrypt(strCipher);
    cout << "text : " << strText << endl;

    return 0;
}
