CC=c++


test: TheGreatGameofGalia.o
	$(CC) -o $@ $< -O0 

TheGreatGameofGalia.o: TheGreatGameofGalia.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
