all: compile link

compile: 
	g++ -c main.cpp -IC:\Users\User\Downloads\Teste\libb\SFML-3.0.0-windows-gcc-14.2.0-mingw-64-bit\SFML-3.0.0\include -DSFML_STATIC

link:
	g++ main.o -o main.exe -LC:\Users\User\Downloads\Teste\libb\SFML-3.0.0-windows-gcc-14.2.0-mingw-64-bit\SFML-3.0.0\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows

clean:

	rm -f main *.o
