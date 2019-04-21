CC=c++


test: SuffixRotation.o
	$(CC) -o $@ $< -O0 

SuffixRotation.o: SuffixRotation.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
