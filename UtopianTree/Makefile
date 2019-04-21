CC=c++


test: UtopianTree.o
	$(CC) -o $@ $< -O0 

UtopianTree.o: UtopianTree.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
