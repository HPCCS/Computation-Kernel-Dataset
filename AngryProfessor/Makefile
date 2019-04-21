CC=c++


test: AngryProfessor.o
	$(CC) -o $@ $< -O0 

AngryProfessor.o: AngryProfessor.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
