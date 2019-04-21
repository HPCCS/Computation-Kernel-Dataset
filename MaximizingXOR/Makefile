CC=c++


test: MaximizingXOR.o
	$(CC) -o $@ $< -O0 

MaximizingXOR.o: MaximizingXOR.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
