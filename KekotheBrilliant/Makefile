CC=c++


test: KekotheBrilliant.o
	$(CC) -o $@ $< -O0 

KekotheBrilliant.o: KekotheBrilliant.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
