CC = g++
OBJS = wec_pt_1.cpp
CFLAGS = -Wall -O2 -std=c++11
BIN = wec21

all: $(BIN)

wec21: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)

clean:
	$(RM) -r wec21 wec21_timed *.o *.dSYM
