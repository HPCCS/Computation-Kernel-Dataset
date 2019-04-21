CC=c++


test: ExtraSweet.o
	$(CC) -o $@ $< -O0 

ExtraSweet.o: ExtraSweet.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
