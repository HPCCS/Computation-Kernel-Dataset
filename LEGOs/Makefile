CC=c++


test: LEGOs.o
	$(CC) -o $@ $< -O0 

LEGOs.o: LEGOs.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
