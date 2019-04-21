CC=c++


test: CarShow.o
	$(CC) -o $@ $< -O0 

CarShow.o: CarShow.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
