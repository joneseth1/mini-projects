CC=g++
SRC := $(PWD)/src
MNIST_ML_ROOT := /c/programs/random-fun/mini-projects/mnist_ml
CFLAGS := -std=c++11 -DEUCLID
INCLUDE_DIR := /c/programs/random-fun/mini-projects/mnist_ml/include
LIB_DIR := /c/programs/random-fun/mini-projects/mnist_ml/lib

all: main

main : $(SRC)/knn.cc
	$(CC) $(CFLAGS) $(SRC)/knn.cc -o main -I$(INCLUDE_DIR) -I$(MNIST_ML_ROOT)/include -L$(LIB_DIR) -ldata

clean:
	rm main


#-I/c/programs/random-fun/mini-projects/mnist_ml/include/
