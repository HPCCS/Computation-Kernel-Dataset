CC=c++


test: ConstructaNumber.o
	$(CC) -o $@ $< -O0 

ConstructaNumber.o: ConstructaNumber.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
