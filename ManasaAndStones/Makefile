CC=c++


test: ManasaAndStones.o
	$(CC) -o $@ $< -O0 

ManasaAndStones.o: ManasaAndStones.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
