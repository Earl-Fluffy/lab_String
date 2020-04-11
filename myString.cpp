#include "myString.h"
#include <iostream>

myString::myString(){
    char temp[]="Hello World !";
    len = sizeof(temp)-1;
    cap=len+1;
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
    content = new char[n+1];
    cap = n+1;
    len = n; // longueur sans le caractère final
    for (int i=0; i<n+1;++i){ // n+1 pour avoir le caractère '\0'
    	content[i]=s[i];
    };

};

char* myString::affiche(){
    return content;
};

int myString::length(){
    return len;
};

myString::~myString(){
	delete []content;
};

int myString::capacity(){
	return cap;
};

bool myString::empty(){
	if (content[0]=='\0'){
		return true;
	}
	return false;
};

void myString::reserve(int n){
	if(n>cap){
		char *temp = new char[n];
		cap=n;
		for(int i=0; i<len+1; ++i){
			temp[i]=content[i];
		}
		delete []content;
		content=temp;
	}
};

void myString::operator= (const char* s){
	delete []content;
	int n=0;
	while (s[n]!= '\0'){
	    n=n+1;
	}
	content = new char[n+1];
	cap = n+1;
	len = n;
	for (int i=0; i<n+1;++i){
		content[i]=s[i];
	};
};

myString myString::operator+(myString added){
	char *newcontent = new char[len+added.length()+1];
	for(int i=0;i<len;++i){
		newcontent[i]=content[i];
	}
	for(int i=0;i<added.length()+1; ++i){
		newcontent[i+len]=added.affiche()[i];
	}
	myString result(newcontent);
	delete []newcontent;
	return result;
 }

int myString::max_size(){
    int maxsize;
    maxsize = 100;
    return maxsize;
};

void myString::resize(size_t n, char c){
    // comment faire pour que resize prenne juste l'argument n, et par défaut c = '\0' ??
    // faire un cas si n = 0 ?
    // si n = 99 alors ok, il y a la place pour le dernier caractère
    if (n >= max_size()){
        std::cout << "size is too large, string overflow" << std::endl;
    }else{
        if (n < len){
        for (int i=0; i<n;i++){
            content[i]=content[i];
        }
        for (int i=n; i<len;i++){
            content[i]='\0';
        }

        }else{
            if (n > len){
                for (int i=0; i<len;i++){
                    content[i]=content[i];}

                    if (c != ' '){
                        for (int i=len; i<n;i++){
                            content[i]=c;}
                        int i=n;       // pour mettre un caractère nul à la fin !!
                        content[i]='\0';
                        }
                    }else{
                        for (int i=len; i<n;i++){
                            content[i]='\0';}
                    }
            }
    len = n; // mettre à jour len
    }
};
