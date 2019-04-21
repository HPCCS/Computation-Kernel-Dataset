CC=c++


test: StockPurchaseDay.o
	$(CC) -o $@ $< -O0 

StockPurchaseDay.o: StockPurchaseDay.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
