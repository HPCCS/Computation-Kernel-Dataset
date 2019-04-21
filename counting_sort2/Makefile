CC=c++


test: counting_sort2.o
	$(CC) -o $@ $< -O0 

counting_sort2.o: counting_sort2.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
