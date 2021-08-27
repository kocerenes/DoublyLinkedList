hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/File.o -c ./src/File.cpp
	g++ -I ./include/ -o ./lib/NumberOne.o -c ./src/NumberOne.cpp
	g++ -I ./include/ -o ./lib/NumberTwo.o -c ./src/NumberTwo.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Iterator.o -c ./src/Iterator.cpp
	g++ -I ./include/ -o ./lib/DoublyLinkedList.o -c ./src/DoublyLinkedList.cpp
	g++ -I ./include/ -o ./lib/ComparisonLists.o -c ./src/ComparisonLists.cpp
	g++ -I ./include/ -o ./bin/test ./lib/File.o ./lib/NumberOne.o ./lib/NumberTwo.o ./lib/Node.o ./lib/Iterator.o ./lib/DoublyLinkedList.o ./lib/ComparisonLists.o ./src/Main.cpp
calistir:
	./bin/test
