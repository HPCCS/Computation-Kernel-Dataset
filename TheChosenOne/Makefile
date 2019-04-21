CC=c++


test: TheChosenOne.o
	$(CC) -o $@ $< -O0 

TheChosenOne.o: TheChosenOne.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
