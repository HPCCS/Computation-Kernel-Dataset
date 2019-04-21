CC=c++


test: LinkedListCycle.o
	$(CC) -o $@ $< -O0 

LinkedListCycle.o: LinkedListCycle.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
