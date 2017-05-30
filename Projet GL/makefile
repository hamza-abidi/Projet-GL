all : lib

lib:  obj/ClearSrc.o obj/Colors.o obj/Cord.o obj/Fight.o obj/Gameplay.o obj/Input.o obj/main.o obj/ManageFile.o obj/Map.o obj/Menu.o obj/Perso.o
	ar -q lib/librairie.a obj/ClearSrc.o obj/Colors.o obj/Cord.o obj/Fight.o obj/Gameplay.o obj/Input.o obj/ManageFile.o obj/Map.o obj/Menu.o obj/Perso.o 
	g++ -std=c++11 -o bin/Executable src/main.cpp src/ClearSrc.cpp src/Colors.cpp src/Cord.cpp src/Fight.cpp src/Gameplay.cpp src/Input.cpp src/ManageFile.cpp src/Map.cpp src/Menu.cpp src/Perso.cpp  lib/librairie.a

obj/main.o :  src/main.cpp
	g++ -std=c++11 -o obj/main.o -c src/main.cpp

obj/ClearSrc.o : src/ClearSrc.cpp
	g++ -std=c++11 -o obj/ClearSrc.o -c src/ClearSrc.cpp
obj/Colors.o : src/Colors.cpp
	g++ -std=c++11 -o obj/Colors.o -c src/Colors.cpp
obj/Cord.o : src/Cord.cpp
	g++ -std=c++11 -o obj/Cord.o -c src/Cord.cpp
obj/Fight.o : src/Fight.cpp
	g++ -std=c++11 -o obj/Fight.o -c src/Fight.cpp
obj/Gameplay.o : src/Gameplay.cpp
	g++ -std=c++11 -o obj/Gameplay.o -c src/Gameplay.cpp
obj/Input.o : src/Input.cpp
	g++ -std=c++11 -o obj/Input.o -c src/Input.cpp
obj/ManageFile.o : src/ManageFile.cpp
	g++ -std=c++11 -o obj/ManageFile.o -c src/ManageFile.cpp
obj/Map.o : src/Map.cpp
	g++ -std=c++11 -o obj/Map.o -c src/Map.cpp
obj/Menu.o : src/Menu.cpp
	g++ -std=c++11 -o obj/Menu.o -c src/Menu.cpp
obj/Perso.o : src/Perso.cpp
	g++ -std=c++11 -o obj/Perso.o -c src/Perso.cpp

clean:
	rm -rf obj/*.o
mrproper: clean
	rm -rf bin/Executable
