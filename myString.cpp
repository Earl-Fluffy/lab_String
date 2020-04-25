#include "myString.h"
#include <iostream>
#include <algorithm>

myString::myString(){
    len=0;
    cap=1;
    content=new char[cap];
    content[0]='\0';

};

myString::myString(const char* s){ //ATTENTION il n'y a pas de protection contre une string de + de 100 char !
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
	if(n>cap && cap != max_size()+1){
		char *temp;
		if (n<(max_size()+1)){
			temp = new char[n];
			cap=n;
		}else{
			temp = new char[max_size()+1];
			cap=max_size()+1;
		}
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

 size_t myString::length(){
    // Returns the length of the myString, in terms of bytes.
    return len;
};

size_t myString::max_size(){
    //Returns the maximum length the myString can reach
    size_t maxsize;
    maxsize = 100;
    return maxsize;
};

void myString::resize(size_t n, char c){ 
    // Resizes the string to a length of n characters.
    // but could not exceed max_size
    if (n > max_size()){
        return ;
    }else{
        // If n is smaller than the current string length,
        // the current value is shortened to its first n character,
        // removing the characters beyond the nth.
        char *temp = new char[n+1]; // allocate memory for temp
        // n+1 because we want the n characters of the string and 1 null character at the end
        if (n < len){
            for (int i=0; i<n;i++){ // temps takes the first n characters of the string
                temp[i]=content[i];
            }

            int i=n; // and at the end of temp we add the null character
            temp[i]='\0';

            // content contains the final string, the resized string
            
	    /*content = new char[n+1];
            for (int i=0; i<len+1;i++){ // len + 1 because we want the last character, the null character to be in final string
                content[i]=temp[i];
            }*/
	    delete []content;
	    content=temp;
	    len=n;

        }else{

        // If n is greater than the current string length,
        // the current content is extended by inserting at the end
        // as many characters as needed to reach a size of n.
            //if (n >= len){

                for (int i=0; i<len;i++){
                    temp[i]=content[i];}
                // temp contains now all the characters of the initial string

                    // If c is specified, the new elements are initialized as copies of c,
                    // otherwise, they are value-initialized characters (null characters).

                    if (c != '\0'){
                        for (int i=len; i<n;i++){
                            temp[i]=c;
		        }
                        // temp contains now all the characters of the initial string AND the character c as many times as necessary so that final string has length=n
                        int i=n;       // null character is added at the end of the final string
                        temp[i]='\0';
                        //}

                    /*content = new char[n+1]; // content will contain the final string
                    for (int i=0; i<n+1;i++){ // n+1 so null character is also in content
                        content[i]=temp[i];}*/
		    delete []content;
		    content=temp;
		    len = n; // update len

                    }else{
			//NOTE :: something's weird here. If the string is full of '\0', the length doesn't change... (number of char until first '\0')
                        for (int i=len; i<n+1;i++){ // n+1 so there are (len-n) null characters to reach string's length=n, and +1 for the final null character
                            temp[i]='\0';}
                        /*content = new char[n+1];
                        for (int i=0; i<n+1;i++){ // n+1 so null character is also in content
                            content[i]=temp[i];}*/

			
			delete []content;
			content=temp;
                    }
        }
        
        cap = n+1; // update cap

    }
};

void myString::resize2(size_t n, char c){
	if (n>max_size()){
		return;
	}
	if (n<cap){
		for (int i=std::min(len,n);i<n;++i){
			content[i]=c;
		}
		for (int i=n;i<cap;++i){
			content[i]='\0';
		}
	} else {
		char *temp = new char[n+1];
		for (int i=0;i<len;++i){
			temp[i]=content[i];
		}
		delete []content;
		for (int i=len;i<n;++i){
			temp[i]=c;
		}
		content=temp;
		cap=n+1;
	}
	if (c=='\0'){
		len=std::min(n,len);
	}else{
		len=n;
	}
}

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

