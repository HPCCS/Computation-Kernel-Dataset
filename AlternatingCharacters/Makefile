CC=c++


test: AlternatingCharacters.o
	$(CC) -o $@ $< -O0 

AlternatingCharacters.o: AlternatingCharacters.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
