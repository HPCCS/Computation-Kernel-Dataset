CC=c++


test: BlackWhiteTree.o
	$(CC) -o $@ $< -O0 

BlackWhiteTree.o: BlackWhiteTree.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
