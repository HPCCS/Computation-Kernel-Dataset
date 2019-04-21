CC=c++


test: FactorialArray.o
	$(CC) -o $@ $< -O0 

FactorialArray.o: FactorialArray.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
