CC=c++


test: BoatTrips.o
	$(CC) -o $@ $< -O0 

BoatTrips.o: BoatTrips.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
