CC=c++


test: TriangleNumbers.o
	$(CC) -o $@ $< -O0 

TriangleNumbers.o: TriangleNumbers.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
