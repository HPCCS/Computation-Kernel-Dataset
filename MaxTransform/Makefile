CC=c++


test: MaxTransform.o
	$(CC) -o $@ $< -O0 

MaxTransform.o: MaxTransform.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
