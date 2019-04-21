CC=c++


test: BoxOperations.o
	$(CC) -o $@ $< -O0 

BoxOperations.o: BoxOperations.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
