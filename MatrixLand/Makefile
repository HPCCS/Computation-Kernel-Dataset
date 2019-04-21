CC=c++


test: MatrixLand.o
	$(CC) -o $@ $< -O0 

MatrixLand.o: MatrixLand.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
