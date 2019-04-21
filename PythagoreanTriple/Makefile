CC=c++


test: PythagoreanTriple.o
	$(CC) -o $@ $< -O0 

PythagoreanTriple.o: PythagoreanTriple.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
