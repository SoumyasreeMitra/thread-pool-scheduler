CXX=g++
CXXFLAGS=-std=c++17 -Wall -pthread

all:
	g++ src/threadpool.cpp tests/test_scheduler.cpp -o scheduler

run:
	./scheduler

clean:
	rm -f scheduler