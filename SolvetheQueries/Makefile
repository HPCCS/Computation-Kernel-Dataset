CC=c++


test: SolvetheQueries.o
	$(CC) -o $@ $< -O0 

SolvetheQueries.o: SolvetheQueries.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
