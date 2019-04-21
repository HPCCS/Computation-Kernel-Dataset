CC=c++


test: SwapNodes.o
	$(CC) -o $@ $< -O0 

SwapNodes.o: SwapNodes.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
