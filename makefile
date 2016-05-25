all:
	g++ -Wall -std=c++11 Project5.cpp huffTree.h Node.h minHeap.h -o encode

clean:
	rm project5