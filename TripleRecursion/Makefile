CC=c++


test: TripleRecursion.o
	$(CC) -o $@ $< -O0 

TripleRecursion.o: TripleRecursion.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
