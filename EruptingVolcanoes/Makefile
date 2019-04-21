CC=c++


test: EruptingVolcanoes.o
	$(CC) -o $@ $< -O0 

EruptingVolcanoes.o: EruptingVolcanoes.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
