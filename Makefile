CC = g++
CFLAGS = -Wall -std=c++11 -fopenmp $(shell pkg-config --cflags opencv4)
LDFLAGS = $(shell pkg-config --cflags --libs opencv4)

all: Secuencial Threads OpenMP

Secuencial: secuencial.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

Threads: threads.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)	

OpenMP: openmp.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f Secuencial Threads OpenMP