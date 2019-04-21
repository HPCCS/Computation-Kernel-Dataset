CC=c++


test: MarchoftheKing.o
	$(CC) -o $@ $< -O0 

MarchoftheKing.o: MarchoftheKing.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
