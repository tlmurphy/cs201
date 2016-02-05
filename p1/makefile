# Here are some notes on makefiles.
#
# This is how I would normally compile...
#
#     gcc -Wall -g heapsort.c heap.c d1.c...
#
# need to make a rule for each object file
# don't forget clean to get rid of the object files

OBJS = Node.o nodetest.o Heap.o Queue.o
nodetest: $(OBJS)
	gcc -Wall -g $(OBJS) -o heapsort
nodetest.o: nodetest.c Node.h Heap.h Queue.h
	gcc -Wall -g -c nodetest.c
Heap.o: Heap.c Node.h
	gcc -Wall -g -c Heap.c
Node.o: Node.c Node.h
	gcc -Wall -g -c Node.c
Queue.o: Queue.c Queue.h Node.h
	gcc -Wall -g -c Queue.c
Stack.o: Stack.c Stack.h Node.h

clean:
	rm -f *.o

# Also include a run
