CC=c++


test: OptimalPolygon.o
	$(CC) -o $@ $< -O0 

OptimalPolygon.o: OptimalPolygon.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
