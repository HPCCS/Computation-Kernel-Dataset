CC=c++


test: SherlockAndSquares.o
	$(CC) -o $@ $< -O0 

SherlockAndSquares.o: SherlockAndSquares.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
