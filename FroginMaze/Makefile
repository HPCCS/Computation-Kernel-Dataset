CC=c++


test: FroginMaze.o
	$(CC) -o $@ $< -O0 

FroginMaze.o: FroginMaze.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
