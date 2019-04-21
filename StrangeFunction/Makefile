CC=c++


test: StrangeFunction.o
	$(CC) -o $@ $< -O0 

StrangeFunction.o: StrangeFunction.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
