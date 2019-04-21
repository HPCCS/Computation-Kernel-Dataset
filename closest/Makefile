CC=c++


test: closest.o
	$(CC) -o $@ $< -O0 

closest.o: closest.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
