CC=c++


test: DistantPairs.o
	$(CC) -o $@ $< -O0 

DistantPairs.o: DistantPairs.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
