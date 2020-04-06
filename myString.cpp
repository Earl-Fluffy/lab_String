#include "myString.h"
#include <iostream>

myString::myString(){
	char temp[]="Hello World !";
	content = new char[sizeof(temp)];
	for (int i=0; i<sizeof(temp);++i){
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
