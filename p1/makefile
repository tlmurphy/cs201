# Here are some notes on makefiles.
#
# This is how I would normally compile...
#
#     gcc -Wall -g heapsort.c heap.c d1.c...
#
# need to make a rule for each object file
# don't forget clean to get rid of the object files

OBJS = node.o nodetest.o heap.o
nodetest: $(OBJS)
	gcc -Wall -g $(OBJS) -o heapsort
nodetest.o: nodetest.c node.h heap.h
	gcc -Wall -g -c nodetest.c
heap.o: heap.c node.h
	gcc -Wall -g -c heap.c
node.o: node.c node.h
clean:
	rm -f *.o
# Also include a run
