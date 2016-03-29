CC = g++ 
CPPFLAGS = -g -std=c++0x 
PROGS = test 
DEF = 

all: $(PROGS)

$(PROGS): test.cpp
	$(CC) $(CPPFLAGS) $(DEF) $@.cpp -o $@ 

clean:
	rm -rf $(PROGS)
