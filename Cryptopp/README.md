## CSCSAes类测试程序
CSCSAes类是对crypto++库中aes加密算法的一个简单封装，  
该类默认构造函数设置密钥为1-8，1-8，1-8，1-8，共32字节256位。  
默认初始向量为：1-4、1-4、1-4、1-4，共16字节，128位。可以使用函数setKey修改。  
使用方法：  
```
CZYAes aes;
string strCipher = aes.Encrypt(strText);
string strText = aes.Encrypt(strCipher);
```

## scsaes256.h
该头文件是对CSCSAes类的封装，向外部提供C的接口。  
使用方法可以参考该test目录下的test.cpp中的测试程序。  

## Cryptopp加密解密库v_5.6.2
使用方法：  
1、解压缩，进入代码目录中  
2、执行 make all static dynamic -f ./GNUmakefile CXXFLAGS='-O2 -fPIC' 进行编译  
3、执行 make install PREFIX='/home/zy/install' 进行安装  
