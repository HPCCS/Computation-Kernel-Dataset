CC=c++


test: AnimalTransport.o
	$(CC) -o $@ $< -O0 

AnimalTransport.o: AnimalTransport.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
