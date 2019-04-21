CC=c++


test: SherlockAndGCD.o
	$(CC) -o $@ $< -O0 

SherlockAndGCD.o: SherlockAndGCD.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
