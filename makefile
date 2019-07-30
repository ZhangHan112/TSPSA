all: TSPSA

TSPSA: TSPSA.o main.o 
	g++ -ggdb -o TSPSA TSPSA.o main.o

TSPSA.o: TSPSA.cpp
	g++ -ggdb -c TSPSA.cpp

main.o: main.cpp
	g++ -ggdb -c main.cpp

plot: 
	gnuplot pic.gp

dep:
	echo "Do nothing"

clean:
	rm -f TSPSA TSPSA *.o

cleanDat:
	rm -f *.dat
