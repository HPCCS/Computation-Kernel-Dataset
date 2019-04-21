CC=c++


test: LexicographicallySmallerorEqualStrings.o
	$(CC) -o $@ $< -O0 

LexicographicallySmallerorEqualStrings.o: LexicographicallySmallerorEqualStrings.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
