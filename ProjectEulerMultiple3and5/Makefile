CC=c++


test: ProjectEulerMultiple3and5.o
	$(CC) -o $@ $< -O0 

ProjectEulerMultiple3and5.o: ProjectEulerMultiple3and5.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
