CC=c++


test: LuckyPurchase.o
	$(CC) -o $@ $< -O0 

LuckyPurchase.o: LuckyPurchase.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
