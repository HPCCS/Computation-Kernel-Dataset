CC=c++


test: Pairs.o
	$(CC) -o $@ $< -O0 

Pairs.o: Pairs.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
