#include "myString.h"


myString::myString(){
	char temp[]="Hello World !";
	content = new char[sizeof(temp)];
	for (int i; sizeof(temp)-1;++i){
		content[i]=temp[i];
	}

};

char* myString::affiche(){
    return content;
};
