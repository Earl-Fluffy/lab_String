#include "myString.h"
#include <cstring>

myString::myString(){
	content = new char[10];
	std::strncpy(content,"Hello World !", 15);
	//content[0] = 'h';
    //content[1] = 'e';
};

char* myString::affiche(){
    return content;
};
