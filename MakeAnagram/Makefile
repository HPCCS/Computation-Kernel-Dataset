CC=c++


test: MakeAnagram.o
	$(CC) -o $@ $< -O0 

MakeAnagram.o: MakeAnagram.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
