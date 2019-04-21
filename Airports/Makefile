CC=c++


test: Airports.o
	$(CC) -o $@ $< -O0 

Airports.o: Airports.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
