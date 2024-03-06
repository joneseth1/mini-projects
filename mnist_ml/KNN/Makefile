CC=g++
SRC := C:/programs/random-fun/mini-projects/mnist_ml/KNN/src
CFLAGS := -std=c++11 -DEUCLID
INCLUDE_DIR := C:/programs/random-fun/mini-projects/mnist_ml/include
LIB_DIR := C:/programs/random-fun/mini-projects/mnist_ml/lib

# Specify the full path to the library file
LIB := $(LIB_DIR)/libdata.so

all: main

main: $(SRC)/knn.cc $(LIB)
	$(CC) $(CFLAGS) $(SRC)/knn.cc -o main -L$(LIB_DIR) -I$(INCLUDE_DIR) $(LIB)

clean:
	rm -f main.exe
