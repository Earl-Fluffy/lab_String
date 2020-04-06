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

myString::myString(const char* s){
    int n;
    n=0;
    while (s[n]!= '\0'){
        n=n+1;
    }
    std::cout << n << std::endl;
    content = new char[n];

    for (int i=0; i<n;++i){
		content[i]=s[i];
	};

};

char* myString::affiche(){
    return content;
};

myString::~myString(){
	delete []content;
};
