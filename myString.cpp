#include "myString.h"


myString::myString(){
	char temp[]="Hello World !";
	content = new char[sizeof(temp)];
	for (int i; sizeof(temp);++i){
		content[i]=temp[i];
	}
	
};

char* myString::affiche(){
    return content;
};
