CC=c++


test: GemStones.o
	$(CC) -o $@ $< -O0 

GemStones.o: GemStones.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
