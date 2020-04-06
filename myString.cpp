#include "myString.h"
#include <iostream>

myString::myString(){
	char temp[]="Hello World !";
	length = sizeof(temp);
	content = new char[length];
	for (int i=0; i<length;++i){
		content[i]=temp[i];
	};

};

char* myString::affiche(){
    return content;
};
