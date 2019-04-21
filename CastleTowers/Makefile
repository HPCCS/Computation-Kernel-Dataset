CC=c++


test: CastleTowers.o
	$(CC) -o $@ $< -O0 

CastleTowers.o: CastleTowers.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
