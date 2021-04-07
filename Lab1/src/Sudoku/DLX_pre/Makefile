CXXFLAGS+=-O2 -ggdb -DDEBUG
CXXFLAGS+=-Wall -Wextra

all: sudoku_solve

sudoku_solve: main.cc neighbor.cc sudoku_basic.cc sudoku_dancing_links.cc
	g++ -O2 -lpthread -o $@ $^
	