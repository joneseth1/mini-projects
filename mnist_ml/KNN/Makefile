CC=g++
SRC := $(MNIST_ML_ROOT)/KNN/src
CFLAGS := -std=c++11 -DEUCLID
INCLUDE_DIR := $(MNIST_ML_ROOT)/include/*
LIB_DIR := $(MNIST_ML_ROOT)/lib


LIB := $(LIB_DIR)/libdata.so

all: main

main: $(SRC)/knn.cc $(LIB)
	$(CC) $(CFLAGS) $(SRC)/knn.cc -o main -L$(LIB_DIR) -I$(INCLUDE_DIR) $(LIB)

clean:
	rm -f main.exe
