CC=c++


test: StrongPassword.o
	$(CC) -o $@ $< -O0 

StrongPassword.o: StrongPassword.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
