CC=g++
SRC := $(PWD)/src
CFLAGS := -std=c++11 -DEUCLID
INCLUDE_DIR := $(PWD)/include



all: main

main : $(SRC)/knn.cc
	$(CC) $(CFLAGS) $(SRC)/knn.cc -o main -L$(LD_LIBRARY_PATH) -I$(INCLUDE_DIR) -ldata

clean:
	rm -f main.exe
