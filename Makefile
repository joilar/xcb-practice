# File: Makefile
# Author: John Oilar
# Date: 07/31/2013
# Description: Builds xcb samples and test programs.

PROGS = xcb-demo-01 xcb-test-01
COMPILER = g++
FLAGS = 

all: $(PROGS)

xcb-demo-01: xcb-demo-01.cpp
	$(COMPILER) $(FLAGS) -o xcb-demo-01 xcb-demo-01.cpp -lxcb -lX11

xcb-test-01: xcb-test-01.cpp
	$(COMPILER) $(FLAGS) -o xcb-test-01 xcb-test-01.cpp -lxcb -lX11

.PHONY: clean
clean:
	rm -f $(PROGS) *.o
