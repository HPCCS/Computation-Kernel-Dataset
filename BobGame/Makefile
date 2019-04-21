CC=c++


test: BobGame.o
	$(CC) -o $@ $< -O0 

BobGame.o: BobGame.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
