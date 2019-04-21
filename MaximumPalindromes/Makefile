CC=c++


test: MaximumPalindromes.o
	$(CC) -o $@ $< -O0 

MaximumPalindromes.o: MaximumPalindromes.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
