CC=c++


test: LetPlayaGame.o
	$(CC) -o $@ $< -O0 

LetPlayaGame.o: LetPlayaGame.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
