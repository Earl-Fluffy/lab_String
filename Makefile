run: myString_gtests.o 
	g++ -o run myString_gtests.o googletest-release-1.10.0/build/lib/libgtest.a googletest-release-1.10.0/build/lib/libgtest_main.a


myString_gtests.o : myString_gtests.cpp
	g++ -c myString_gtests.cpp -o myString_gtests.o -Igoogletest-release-1.10.0/googletest/include/ -std=c++11


check: main.o myString.o
	g++ -o check main.o myString.o

main.o: main.cpp myString.h
	g++ -o main.o -c main.cpp 

myString.o: myString.cpp myString.h
	g++ -o myString.o -c myString.cpp

clean:
	rm check main.o myString.o run myString_gtests.o

