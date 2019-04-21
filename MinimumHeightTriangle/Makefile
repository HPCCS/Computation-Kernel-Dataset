CC=c++


test: MinimumHeightTriangle.o
	$(CC) -o $@ $< -O0 

MinimumHeightTriangle.o: MinimumHeightTriangle.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
