DEBUG		= -g

CCFLAGS		= $(DEBUG) -Wall
CXXFLAGS 	= $(DEBUG) -Wall

LD		= g++ $(DEBUG)

AR 		= ar -r
RANLIB  	= ranlib

REMOVE  	= rm -f

INCLUDES	= -I.
DEFINES		=

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -c $< -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) -c $< -o $@

all: send sendTriState sendRev sendRevBHC

send: RCSwitch.o send.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

sendTriState: RCSwitch.o sendTriState.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

sendRev: RCSwitch.o sendRev.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

sendRevBHC: RCSwitch.o sendRevBHC.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

clean:
	$(RM) *.o send sendTriState sendRev sendRevBHC
