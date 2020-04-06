#include "myString.h"
#include <iostream>

myString::myString(){
	char temp[]="Hello World !";
	len = sizeof(temp)-1;
	content = new char[len+1];
	for (int i=0; i<len+1;++i){
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
    len = n; // longueur sans le caractère final
    for (int i=0; i<n+1;++i){ // n+1 pour avoir le caractère '\0'
		content[i]=s[i];
	};

};

char* myString::affiche(){
    return content;
};

myString::length(){
    return len;
};

myString::~myString(){
	delete []content;
};
