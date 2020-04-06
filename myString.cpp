#include "myString.h"

myString::myString(){
	content = new char[10];
	content[0] = 'h';
    content[1] = 'e';
};

char myString::affiche(){
    return content[0];
};
