CC=c++


test: ExtraLongFactorials.o
	$(CC) -o $@ $< -O0 

ExtraLongFactorials.o: ExtraLongFactorials.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
