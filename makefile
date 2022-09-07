.PHONY: all ut_all

SRC = cat.h dog.h pet.h yard.h
TEST = ut_cat.h ut_dog.h ut_yard.h

all: ut_all 

ut_all: $(SRC) $(TEST)
	g++ -std=c++11 -Wfatal-errors ut_main.cpp -o ut_all -lgtest -lpthread