CC = g++
COMFLAG  	= -D__LINUX__
SCSDBDIR 	= ..
IFLAG		= -I$(SCSDBDIR)/include/
LFLAG 		= -L$(SCSDBDIR)/lib/
FLAG 		= $(DEBUGFLAG) $(IFLAG) $(LFLAG)

all : test
test : test.cpp
	$(CC) -o $@ $^ $(FLAG) ../lib/libzyaes256.a -lpthread -Wall -lrt -O

clean:
	rm -rf *.o test

