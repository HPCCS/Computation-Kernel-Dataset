CC=c++


test: CountPairs.o
	$(CC) -o $@ $< -O0 

CountPairs.o: CountPairs.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
