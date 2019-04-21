CC=c++


test: LonelyInteger.o
	$(CC) -o $@ $< -O0 

LonelyInteger.o: LonelyInteger.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
