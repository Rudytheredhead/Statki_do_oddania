CXX = g++
CXXFLAGS = -Wall
LFLAGS =
OBJS = main.o Statek.o Punkt.o Gracz.o Tryb_gry.o
all: prog
prog: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@
clean:
	rm -f *.o prog
.PHONY: all clean
