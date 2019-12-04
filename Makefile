all:
	clear
	sudo rm -rf projet.exe projet.flex.cpp projet.bison.cpp projet.bison.hpp
	flex -o projet.flex.cpp projet.flex
	bison -d projet.bison -o projet.bison.cpp
	g++ -o projet projet.flex.cpp projet.bison.cpp  -w -I/usr/include/python2.7 -lpython2.7
	./projet testFile