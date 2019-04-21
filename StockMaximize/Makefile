CC=c++


test: StockMaximize.o
	$(CC) -o $@ $< -O0 

StockMaximize.o: StockMaximize.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
