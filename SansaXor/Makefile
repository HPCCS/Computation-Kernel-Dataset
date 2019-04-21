CC=c++


test: SansaXor.o
	$(CC) -o $@ $< -O0 

SansaXor.o: SansaXor.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
