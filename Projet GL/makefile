all : lib

lib:  obj/Colors.o obj/Input.o obj/main.o obj/ManageFile.o obj/Map.o obj/Window.o
	ar -q lib/librairie.a obj/Colors.o obj/Input.o obj/ManageFile.o obj/Map.o obj/Window.o 
	g++ -std=c++11 -pthread -o bin/Executable src/main.cpp src/Colors.cpp src/Input.cpp src/ManageFile.cpp src/Map.cpp src/Window.cpp  -L /usr/include/SFML -lsfml-graphics -lsfml-window -lsfml-system lib/librairie.a

obj/main.o :  src/main.cpp
	g++ -std=c++11 -pthread -o obj/main.o -c src/main.cpp

obj/Colors.o : src/Colors.cpp
	g++ -std=c++11 -pthread -o obj/Colors.o -c src/Colors.cpp
obj/Input.o : src/Input.cpp
	g++ -std=c++11 -pthread -o obj/Input.o -c src/Input.cpp
obj/ManageFile.o : src/ManageFile.cpp
	g++ -std=c++11 -pthread -o obj/ManageFile.o -c src/ManageFile.cpp
obj/Map.o : src/Map.cpp
	g++ -std=c++11 -pthread -o obj/Map.o -c src/Map.cpp
obj/Window.o : src/Window.cpp
	g++ -std=c++11 -pthread -o obj/Window.o -c src/Window.cpp

clean:
	rm -rf obj/*.o
mrproper: clean
	rm -rf bin/Executable
