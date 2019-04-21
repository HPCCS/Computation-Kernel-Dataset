CC=c++


test: DivisorExploration3.o
	$(CC) -o $@ $< -O0 

DivisorExploration3.o: DivisorExploration3.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
