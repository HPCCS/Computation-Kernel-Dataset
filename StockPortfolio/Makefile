CC=c++


test: StockPortfolio.o
	$(CC) -o $@ $< -O0 

StockPortfolio.o: StockPortfolio.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
