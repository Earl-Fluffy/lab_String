check: main.o myString.o
	g++ -o check main.o myString.o

main.o: main.cpp myString.h
	g++ -o main.o -c main.cpp 

myString.o: myString.cpp myString.h
	g++ -o myString.o -c myString.cpp

clean:
	rm check main.o myString.o

