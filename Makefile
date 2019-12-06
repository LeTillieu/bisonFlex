all:
	clear
	rm -rf projet.exe projet.flex.cpp projet.bison.cpp projet.bison.hpp
	flex -o projet.flex.cpp projet.flex
	bison -d projet.bison -o projet.bison.cpp
	g++ -o projet projet.flex.cpp projet.bison.cpp -lsfml-graphics -lsfml-window -lsfml-system -w
	sudo ./projet testFile