CC=c++


test: TileStackingProblem.o
	$(CC) -o $@ $< -O0 

TileStackingProblem.o: TileStackingProblem.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
