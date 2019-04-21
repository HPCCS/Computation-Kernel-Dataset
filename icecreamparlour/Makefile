CC=c++


test: icecreamparlour.o
	$(CC) -o $@ $< -O0 

icecreamparlour.o: icecreamparlour.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
