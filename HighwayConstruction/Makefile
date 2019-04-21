CC=c++


test: HighwayConstruction.o
	$(CC) -o $@ $< -O0 

HighwayConstruction.o: HighwayConstruction.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
