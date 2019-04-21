CC=c++


test: AngryChildrens.o
	$(CC) -o $@ $< -O0 

AngryChildrens.o: AngryChildrens.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
