CC=c++


test: PrimeNumberandQueries.o
	$(CC) -o $@ $< -O0 

PrimeNumberandQueries.o: PrimeNumberandQueries.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
