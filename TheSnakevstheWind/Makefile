CC=c++


test: TheSnakevstheWind.o
	$(CC) -o $@ $< -O0 

TheSnakevstheWind.o: TheSnakevstheWind.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
