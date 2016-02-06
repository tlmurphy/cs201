# Here are some notes on makefiles.
#
# This is how I would normally compile...
#
#     gcc -Wall -g heapsort.c heap.c d1.c...
#
# need to make a rule for each object file
# don't forget clean to get rid of the object files

OBJS = main.o Node.o Heap.o Queue.o Stack.o TreeNode.o
main: $(OBJS)
	gcc -Wall -g $(OBJS) -o heapsort
main.o: main.c Heap.h Queue.h Stack.h
	gcc -Wall -g -c main.c
Heap.o: Heap.c Node.h
	gcc -Wall -g -c Heap.c
Node.o: Node.c Node.h TreeNode.h
	gcc -Wall -g -c Node.c
TreeNode.o: TreeNode.c TreeNode.h
	gcc -Wall -g -c TreeNode.c
Queue.o: Queue.c Queue.h Node.h
	gcc -Wall -g -c Queue.c
Stack.o: Stack.c Stack.h Node.h
	gcc -Wall -g -c Stack.c

clean:
	rm -f *.o

# Also include a run
