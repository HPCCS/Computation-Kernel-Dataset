CC=c++


test: SherlockAndPairs.o
	$(CC) -o $@ $< -O0 

SherlockAndPairs.o: SherlockAndPairs.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
