CC=c++


test: WireRemoval.o
	$(CC) -o $@ $< -O0 

WireRemoval.o: WireRemoval.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
