all:	ReverseLinkedList
	echo
	make TopSolution

ReverseLinkedList:	ReverseLinkedList.cpp
	g++ -std=c++2a -Wall -g -o build/ReverseLinkedList ReverseLinkedList.cpp
	./build/ReverseLinkedList

TopSolution:	TopSolution.cpp
	g++ -std=c++2a -Wall -g -o build/TopSolution TopSolution.cpp
	./build/TopSolution

clean:
	rm -f build/*
	clear