CC=g++

driver: Point.o Cluster.o driver.o
	$(CC) driver.o Point.o Cluster.o -o driver

Point.o: Point.cpp Point.h
	$(CC) -c Point.cpp

Cluster.o: Cluster.cpp Cluster.h
	$(CC) -c Cluster.cpp

driver.o: driver.cpp
	$(CC) -c driver.cpp

run: driver
	./driver

clean:
	rm *.o driver
