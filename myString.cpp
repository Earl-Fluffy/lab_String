#include "myString.h"
#include <iostream>

myString::myString(){
	char temp[]="Hello World !";
	length = sizeof(temp)-1;
	content = new char[length+1];
	for (int i=0; i<length+1;++i){
		content[i]=temp[i];
	};

};

myString::myString(const char* s){
    int n;
    n=0;
    while (s[n]!= '\0'){
        n=n+1;
    }
    content = new char[n];
    length = n-1;
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
