CC=c++


test: Keywords.o
	$(CC) -o $@ $< -O0 

Keywords.o: Keywords.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
