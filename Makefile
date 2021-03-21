main: Pyramid.o PyramidNode.o main.o
	g++ -o main Pyramid.o PyramidNode.o main.o

Pyramid.o: Pyramid.cpp
	g++ -c Pyramid.cpp

PyramidNode.o: PyramidNode.cpp
	g++ -c PyramidNode.cpp

main.o: main.cpp
	g++ -c main.cpp