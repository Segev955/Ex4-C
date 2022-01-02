CC=gcc
Ar=ar
FLAGS = -Wall -g
OBJECT=main.o graph.o graphAlgo.o

all: graph

graph: $(OBJECT)
	$(CC) $(FLAGS) -o graph $(OBJECT)
	
main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c

graph.o: graph.c graph.h
	$(CC) $(FLAGS) -c graph.c

graphAlgo.o: graphAlgo.c graph.h
	$(CC) $(FLAGS) -c graphAlgo.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so graph
