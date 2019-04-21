CC=c++


test: ChocolateFeast.o
	$(CC) -o $@ $< -O0 

ChocolateFeast.o: ChocolateFeast.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
