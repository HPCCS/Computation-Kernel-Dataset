CC=c++


test: MissingNumber.o
	$(CC) -o $@ $< -O0 

MissingNumber.o: MissingNumber.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
