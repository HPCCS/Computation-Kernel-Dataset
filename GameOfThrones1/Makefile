CC=c++


test: GameOfThrones1.o
	$(CC) -o $@ $< -O0 

GameOfThrones1.o: GameOfThrones1.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
