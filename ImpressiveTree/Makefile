CC=c++


test: ImpressiveTree.o
	$(CC) -o $@ $< -O0 

ImpressiveTree.o: ImpressiveTree.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
