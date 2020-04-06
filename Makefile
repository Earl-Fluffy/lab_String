run: main.o
	g++ main.o -o run

main.o: main.cpp
	g++ -c main.cpp -o main.o

clean:
	rm run main.o