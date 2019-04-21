CC=c++


test: FindDigits.o
	$(CC) -o $@ $< -O0 

FindDigits.o: FindDigits.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
