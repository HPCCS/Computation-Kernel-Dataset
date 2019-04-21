CC=c++


test: MaximizeProfit.o
	$(CC) -o $@ $< -O0 

MaximizeProfit.o: MaximizeProfit.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
