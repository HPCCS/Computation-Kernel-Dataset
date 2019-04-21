CC=c++


test: BreakingSticks.o
	$(CC) -o $@ $< -O0 

BreakingSticks.o: BreakingSticks.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
