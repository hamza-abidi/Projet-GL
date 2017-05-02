all : lib

lib:  obj/Colors.o obj/fight.o obj/Gameplay.o obj/Input.o obj/main.o obj/ManageFile.o obj/Map.o obj/perso.o
	ar -q lib/librairie.a obj/Colors.o obj/fight.o obj/Gameplay.o obj/Input.o obj/ManageFile.o obj/Map.o obj/perso.o 
	g++ -std=c++11 -o bin/Executable src/main.cpp src/Colors.cpp src/fight.cpp src/Gameplay.cpp src/Input.cpp src/ManageFile.cpp src/Map.cpp src/perso.cpp   lib/librairie.a

obj/main.o :  src/main.cpp
	g++ -std=c++11 -o obj/main.o -c src/main.cpp

obj/Colors.o : src/Colors.cpp
	g++ -std=c++11 -o obj/Colors.o -c src/Colors.cpp
obj/fight.o : src/fight.cpp
	g++ -std=c++11 -o obj/fight.o -c src/fight.cpp
obj/Gameplay.o : src/Gameplay.cpp
	g++ -std=c++11 -o obj/Gameplay.o -c src/Gameplay.cpp
obj/Input.o : src/Input.cpp
	g++ -std=c++11 -o obj/Input.o -c src/Input.cpp
obj/ManageFile.o : src/ManageFile.cpp
	g++ -std=c++11 -o obj/ManageFile.o -c src/ManageFile.cpp
obj/Map.o : src/Map.cpp
	g++ -std=c++11 -o obj/Map.o -c src/Map.cpp
obj/perso.o : src/perso.cpp
	g++ -std=c++11 -o obj/perso.o -c src/perso.cpp

clean:
	rm -rf obj/*.o
mrproper: clean
	rm -rf bin/Executable
