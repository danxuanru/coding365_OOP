.PHONY: all ut_all
all: ut_all

ut_all: ut_main.cpp
	g++ -std=c++11 -Wfatal-errors ut_main.cpp -o ut_all -lgtest -lpthread

.PHONY: clean
clean:
	rm -f ut_all

