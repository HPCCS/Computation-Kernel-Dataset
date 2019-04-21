CC=c++


test: TwoStrings.o
	$(CC) -o $@ $< -O0 

TwoStrings.o: TwoStrings.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
