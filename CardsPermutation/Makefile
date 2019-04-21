CC=c++


test: CardsPermutation.o
	$(CC) -o $@ $< -O0 

CardsPermutation.o: CardsPermutation.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
