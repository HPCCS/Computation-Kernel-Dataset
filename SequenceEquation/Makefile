CC=c++


test: SequenceEquation.o
	$(CC) -o $@ $< -O0 

SequenceEquation.o: SequenceEquation.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
