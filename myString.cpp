#include "myString.h"
#include <iostream>

myString::myString(){
    len=0;
    cap=1;
    content=new char[cap];
    content[0]='\0';

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

const char* myString::c_str() const{
    return content;
};

size_t myString::length(){
    // Returns the length of the myString, in terms of bytes.
    return len;
};

myString::~myString(){
	delete []content;
};

size_t myString::capacity(){
	return cap;
};

bool myString::empty(){
	if (content[0]=='\0'){
		return true;
	}
	return false;
};

void myString::reserve(size_t n){
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
		newcontent[i+len]=added.c_str()[i];
	}
	myString result(newcontent);
	delete []newcontent;
	return result;
 }

size_t myString::max_size(){
    //Returns the maximum length the myString can reach
    size_t maxsize;
    maxsize = 100;
    return maxsize;
};

void myString::resize(size_t n, char c){
    // comment faire pour que resize prenne juste l'argument n, et par défaut c = '\0' ??

    // Resizes the string to a length of n characters.
    // but could not exceed max_size
    if (n > max_size()){
        std::cout << "size is too large, string overflow" << std::endl;
    }else{
        // If n is smaller than the current string length,
        // the current value is shortened to its first n character,
        // removing the characters beyond the nth.
        char *temp = new char[cap + n+1]; // temp is a temporary

        if (n < len){
            for (int i=0; i<n;i++){
                temp[i]=content[i];
            }
            for (int i=n; i<len;i++){
                temp[i]='\0';
            }

            // on met dans content le string final
            content = new char[cap + n+1];
            for (int i=0; i<len;i++){
                content[i]=temp[i];
            }


        }else{

        // If n is greater than the current string length,
        // the current content is extended by inserting at the end
        // as many characters as needed to reach a size of n.
            if (n > len){
                for (int i=0; i<len;i++){
                    temp[i]=content[i];}
                    // If c is specified, the new elements are initialized as copies of c,
                    // otherwise, they are value-initialized characters (null characters).

                    if (c != '\0'){
                        for (int i=len; i<n;i++){
                            temp[i]=c;}
                        int i=n;       // we need to put a null character at the end of myString
                        temp[i]='\0';
                        }
                    content = new char[cap + n+1];
                    for (int i=0; i<n;i++){
                        content[i]=temp[i];}
                    }else{
                        for (int i=len; i<n;i++){
                            temp[i]='\0';}
                        content = new char[cap + n+1];
                        for (int i=0; i<n;i++){
                            content[i]=temp[i];}
                    }
            }
    len = n; // update len
    cap = n+1; // update cap

    }
};

myString& myString::operator= (const myString& str){
    // Assigns a new value to the string, replacing its current contents
    delete []content;
    content = new char[str.cap]; // on réserve un tableau de taille str.cap
    len = str.len;
    cap = str.cap;
    for(int i=0;i<str.len+1;++i){
        content[i] = str.content[i];
    }
};

myString myString::operator+ (char rhs){
    // Returns a newly constructed string object with its value being the concatenation
    // of the characters in current object myString followed by those of rhs.
    char *newcontent = new char[len+1];
	for(int i=0;i<len;i++){
		newcontent[i]=content[i];
	}
	newcontent[len]=rhs;

	myString result(newcontent);
	delete []newcontent;
	return result;

};

