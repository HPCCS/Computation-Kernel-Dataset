CC=c++


test: CostlyIntervals.o
	$(CC) -o $@ $< -O0 

CostlyIntervals.o: CostlyIntervals.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
