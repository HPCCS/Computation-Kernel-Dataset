CC=c++


test: MinimumEdgesinaLayeredGraph.o
	$(CC) -o $@ $< -O0 

MinimumEdgesinaLayeredGraph.o: MinimumEdgesinaLayeredGraph.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
