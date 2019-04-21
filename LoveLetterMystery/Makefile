CC=c++


test: LoveLetterMystery.o
	$(CC) -o $@ $< -O0 

LoveLetterMystery.o: LoveLetterMystery.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
