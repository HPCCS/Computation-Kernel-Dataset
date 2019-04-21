CC=c++


test: MutualIndivisibility.o
	$(CC) -o $@ $< -O0 

MutualIndivisibility.o: MutualIndivisibility.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
