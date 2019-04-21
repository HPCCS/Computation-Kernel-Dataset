CC=c++


test: AfraidoftheDark.o
	$(CC) -o $@ $< -O0 

AfraidoftheDark.o: AfraidoftheDark.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
