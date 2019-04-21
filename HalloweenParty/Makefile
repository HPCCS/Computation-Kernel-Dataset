CC=c++


test: HalloweenParty.o
	$(CC) -o $@ $< -O0 

HalloweenParty.o: HalloweenParty.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
