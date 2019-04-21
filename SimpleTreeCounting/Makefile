CC=c++


test: SimpleTreeCounting.o
	$(CC) -o $@ $< -O0 

SimpleTreeCounting.o: SimpleTreeCounting.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
