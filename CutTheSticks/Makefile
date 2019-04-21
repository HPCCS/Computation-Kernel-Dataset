CC=c++

test: CutTheSticks.o
	$(CC) -o $@ $< -O0 

CutTheSticks.o: CutTheSticks.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
