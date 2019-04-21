CC=c++


test: PolynomialDivision.o
	$(CC) -o $@ $< -O0 

PolynomialDivision.o: PolynomialDivision.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
