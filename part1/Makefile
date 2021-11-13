CC = clang++
OBJS = wec_pt_1.cpp 
CFLAGS = -Wall -O2 -std=c++11
BIN = wec21

all: $(BIN)

wec21: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)

clean:
	$(RM) -r $(BIN) *.o *.dSYM