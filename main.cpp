#include "myString.h"
#include <iostream>

int main(){
    myString test;
    char chaine[] = "hello world";
    std::cout << "premier test : " << test.affiche() << std::endl;

    std::cout << "avec char : " << chaine[0] << std::endl;

    myString text("a character sequence");
    myString empty("");

    std::cout << "essai avec constructeur text : " << text.affiche() << std::endl;

    std::cout << "taille de text : " << text.length() << std::endl;

    std::cout << "max_size de text : " << text.max_size() << std::endl;

    std::cout << "capacity de text : " << text.capacity() << std::endl;

    std::cout << "is an empty string empty : " << empty.empty() << std::endl;

    text.reserve(30);
    std::cout << "capacity de text après reserve(30) : " << text.capacity() << std::endl;

    text="a new character sequence";
    std::cout << "Modified text string with new content " << text.affiche() << " length " << text.length() << " capacity " << text.capacity() << std::endl;

    std::cout << "test de l'addition : " << (text+test).affiche() << std::endl;
	return 0;
};
