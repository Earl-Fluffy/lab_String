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

    // test de resize
    myString s1("julie");
    std::cout << "affiche s1 avant : " << s1.affiche() << std::endl;
    std::cout << "taille de s1 avant : " << s1.length() << std::endl;
    size_t n = 3;
    s1.resize(n,' ');
    std::cout << "affiche s1 apres : " << s1.affiche() << std::endl;
    std::cout << "taille de s1 apres : " << s1.length() << std::endl;

    myString s2("julie");
    std::cout << "affiche s2 avant : " << s2.affiche() << std::endl;
    std::cout << "taille de s2 avant : " << s2.length() << std::endl;
    size_t n2 = 10;
    s2.resize(n2,'a');
    std::cout << "affiche s2 apres : " << s2.affiche() << std::endl;
    std::cout << "taille de s2 apres : " << s2.length() << std::endl;

    myString s3("julie");
    std::cout << "affiche s3 avant : " << s3.affiche() << std::endl;
    std::cout << "taille de s3 avant : " << s3.length() << std::endl;
    size_t n3 = 10;
    s3.resize(n3,' ');
    std::cout << "affiche s3 apres : " << s3.affiche() << std::endl;
    std::cout << "taille de s3 apres : " << s3.length() << std::endl;

    myString s4("julie");
    std::cout << "affiche s4 avant : " << s4.affiche() << std::endl;
    std::cout << "taille de s4 avant : " << s4.length() << std::endl;
    size_t n4 = 5;
    s4.resize(n4,' ');
    std::cout << "affiche s4 apres : " << s4.affiche() << std::endl;
    std::cout << "taille de s4 apres : " << s4.length() << std::endl;

    // test resize avec n > max_size
    myString s5("julie");
    std::cout << "affiche s5 avant : " << s5.affiche() << std::endl;
    std::cout << "taille de s5 avant : " << s5.length() << std::endl;
    size_t n5 = 100;
    s5.resize(n5,'a');
    std::cout << "affiche s5 apres : " << s5.affiche() << std::endl;
    std::cout << "taille de s5 apres : " << s5.length() << std::endl;

    // test resize avec n = 0
    myString s6("julie");
    std::cout << "affiche s6 avant : " << s6.affiche() << std::endl;
    std::cout << "taille de s6 avant : " << s6.length() << std::endl;
    size_t n6 = 0;
    s6.resize(n6,'a');
    std::cout << "affiche s6 apres : " << s6.affiche() << std::endl;
    std::cout << "taille de s6 apres : " << s6.length() << std::endl;

    myString s7("jb");
    myString s8("laura");
    std::cout << "affiche s7 avant opérateur = : " << s7.affiche() << std::endl;
    s7 = s8;
    std::cout << "affiche s7 après opérateur = : " << s7.affiche() << std::endl;
    std::cout << "mettre length : " << s7.length() << std::endl;
    std::cout << "mettre capacity : " << s7.capacity() << std::endl;

	return 0;
};
