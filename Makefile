all: compile link

compile: 
	g++ -c main.cpp -I"...\include" -DSFML_STATIC

link:
	g++ main.o -o main.exe -L"...\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows

clean:

	rm -f main *.o
