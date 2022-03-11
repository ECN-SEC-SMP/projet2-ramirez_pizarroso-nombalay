all: main.out

clean:
	rm *.o
	rm *.out

main.out: main.o carte.o joueur.o pioche.o plateau.o joueurIA.o
	g++ -o main.out main.o carte.o joueur.o joueurIA.o pioche.o plateau.o

main.o: main.cpp
	g++ -c main.cpp

carte.o: carte.hpp carte.cpp
	g++ -c carte.cpp

joueur.o: joueur.hpp joueur.cpp
	g++ -c joueur.cpp

joueurIA.o: joueurIA.hpp joueurIA.cpp
	g++ -c joueurIA.cpp

pioche.o: pioche.hpp pioche.cpp
	g++ -c pioche.cpp

plateau.o: plateau.hpp plateau.cpp
	g++ -c plateau.cpp
