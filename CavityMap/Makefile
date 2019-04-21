CC=c++


test: CavityMap.o
	$(CC) -o $@ $< -O0 

CavityMap.o: CavityMap.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
