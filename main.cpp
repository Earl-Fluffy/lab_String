#include "myString.h"
#include <iostream>

int main(){
    myString test;
    char chaine[] = "hello world";
    std::cout << "premier test : " << test.affiche() << std::endl;

    std::cout << "avec char : " << chaine[0] << std::endl;

    myString text("a character sequence");

    std::cout << "essai avec constructeur text : " << text.affiche() << std::endl;

    std::cout << "taille de text : " << text.length() << std::endl;

	return 0;
};
