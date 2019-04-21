CC=c++


test: Service_lane.o
	$(CC) -o $@ $< -O0 

Service_lane.o: Service_lane.cpp
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
