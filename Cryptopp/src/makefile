# INSTALLDIR是cryptopp库安装目录，cryptopp库的安装请看根目录的readme.txt
CC 		= g++ -fPIC 
INSTALLDIR = /home/zy/install
COMDIR  = ..
IFLAG 	= -I$(INSTALLDIR)/include/cryptopp -I$(COMDIR)/include/
LFLAG 	= -L$(INSTALLDIR)/lib/
FLAG 	= $(IFLAG) $(LFLAG) $(DEBUGFLAG)
OBJECTS = zyaes256.o zyaes.o

all:libzyaes256.a libzyaes256.so
libzyaes256.a:$(OBJECTS)
	ar -x $(INSTALLDIR)/lib/libcryptopp.a
	ar -rc $@ *.o
	cp -rf libzyaes256.a ../lib/

libzyaes256.so:$(OBJECTS)
	$(CC) -shared -o $@ $^
	cp -rf libzyaes256.so ../lib/
	
zyaes256.o:zyaes.o zyaes256.cpp
	$(CC) -c zyaes256.cpp -o $@ $(FLAG)

zyaes.o:zyaes.cpp
	$(CC) -c $< -o $@ $(FLAG)

clean:
	rm -rf *.o libzyaes256.a libzyaes256.so
