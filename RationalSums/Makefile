CC=c++


test: RationalSums.o
	$(CC) -o $@ $< -O0 

RationalSums.o: RationalSums.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
