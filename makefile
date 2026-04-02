
CC  = clang
CXX = clang++

CFLAGS   = -Iinclude
CXXFLAGS = -std=c++17 -Iinclude -I/opt/homebrew/include
LDLIBS   = -L/opt/homebrew/lib -lgtest -lgtest_main -lpthread

SRC_C   = src/io.c src/dinamic_massive.c src/Matrix.c
SRC_MAIN= src/main.c
SRC_TEST= tests/test.cpp

OBJ_C   = $(SRC_C:.c=.o)
OBJ_MAIN= $(SRC_MAIN:.c=.o)

main: $(OBJ_C) $(OBJ_MAIN)
	$(CC) $^ -o $@
	./$@

test: $(OBJ_C)
	$(CXX) $(SRC_TEST) $(OBJ_C) -o $@ $(CXXFLAGS) $(LDLIBS)
	./$@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_C) $(OBJ_MAIN) main test

.PHONY: main test clean

