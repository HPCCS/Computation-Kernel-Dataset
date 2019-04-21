CC=c++


test: TwoArrays.o
	$(CC) -o $@ $< -O0 

TwoArrays.o: TwoArrays.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
