CC = g++
OBJS = wec21.cpp 
CFLAGS = -g -Wall -std=c++11
BIN = wec21

all: $(BIN)

wec21: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)

clean:
	$(RM) -r $(BIN) *.o *.dSYM