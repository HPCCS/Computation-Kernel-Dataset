CC=c++


test: CameraPurchase.o
	$(CC) -o $@ $< -O0 

CameraPurchase.o: CameraPurchase.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
