CC=c++


test: 3DSurfaceArea.o
	$(CC) -o $@ $< -O0 

3DSurfaceArea.o: 3DSurfaceArea.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
