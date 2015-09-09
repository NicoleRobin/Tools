# DEBUGFLAG可以用于传递参数，例如编译调试版本：
# make clean;make DEBUGFLAG='-g'
CC 	 = g++
FLAG = -fPIC $(DEBUGFLAG)
all: libtranscharset.so libtranscharset.a

libtranscharset.so: TransCharSet.o
	$(CC) -o $@ $< -shared $(FLAG)
	
libtranscharset.a: TransCharSet.o
	ar -rc $@ $<

TransCharSet.o: TransCharSet.cpp
	$(CC) -o $@ -c $<

clean:
	rm -rf libtranscharset.* TransCharSet.o