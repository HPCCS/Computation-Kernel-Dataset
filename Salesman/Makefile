CC=c++


test: Salesman.o
	$(CC) -o $@ $< -O0 

Salesman.o: Salesman.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
