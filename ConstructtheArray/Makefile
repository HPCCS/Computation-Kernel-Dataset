CC=c++


test: ConstructtheArray.o
	$(CC) -o $@ $< -O0 

ConstructtheArray.o: ConstructtheArray.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
