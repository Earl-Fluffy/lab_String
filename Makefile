myString_gtests.o: myString_gtests.cpp myString.cpp
	g++ -c myString_gtests.cpp -o myString_gtests.o -Igoogletest-release-1.10.0/googletest/include/ -std=c++11

check: myString_gtests.o
	g++ -o check myString_gtests.o googletest-release-1.10.0/build/lib/libgtest.a googletest-release-1.10.0/build/lib/libgtest_main.a -pthread
	./check
	
	rm ./check myString_gtests.o