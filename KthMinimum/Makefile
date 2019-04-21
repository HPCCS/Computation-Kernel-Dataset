CC=c++


test: KthMinimum.o
	$(CC) -o $@ $< -O0 

KthMinimum.o: KthMinimum.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
