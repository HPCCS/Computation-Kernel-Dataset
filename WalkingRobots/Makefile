CC=c++


test: WalkingRobots.o
	$(CC) -o $@ $< -O0 

WalkingRobots.o: WalkingRobots.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
