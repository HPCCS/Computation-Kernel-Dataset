CC=c++


test: OrderStrings.o
	$(CC) -o $@ $< -O0 

OrderStrings.o: OrderStrings.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
