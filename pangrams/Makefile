CC=c++


test: pangrams.o
	$(CC) -o $@ $< -O0 

pangrams.o: pangrams.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
