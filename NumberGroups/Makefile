CC=c++


test: NumberGroups.o
	$(CC) -o $@ $< -O0 

NumberGroups.o: NumberGroups.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
