CC=c++


test: FunnyString.o
	$(CC) -o $@ $< -O0 

FunnyString.o: FunnyString.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
