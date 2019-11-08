CFLAGS = -g -Wall -W -Wshadow -Wuninitialized -O
CC     = g++
LINK   = g++
OFILES = pqueue.o testpqueue.o

test: testpqueue
	chmod u+x dotest
	./dotest

trace: testpqueue
	chmod u+x dotest
	./dotest -t

debug: testpqueue
	gdb ./testpqueue

testpqueue : $(OFILES)
	$(LINK) -o testpqueue $(OFILES) 

pqueue.o: pqueue.cpp pqueue.h
	$(CC) $(CFLAGS) -c pqueue.cpp

testpqueue.o: testpqueue.cpp pqueue.h
	$(CC) $(CFLAGS) -c testpqueue.cpp

clean: 
	rm $(OFILES) testpqueue
