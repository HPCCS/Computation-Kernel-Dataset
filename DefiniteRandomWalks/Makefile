CC=c++


test: DefiniteRandomWalks.o
	$(CC) -o $@ $< -O0 

DefiniteRandomWalks.o: DefiniteRandomWalks.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
