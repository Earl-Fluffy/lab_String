#include "gtest/gtest.h"
#include "myString.cpp"
#include <string> // cette classe permet de comparer � notre classe myString
#include <stdlib.h> // used for size_t

TEST(GTestTests, Stringstests) {
    // test of default constructor
    myString test;
    EXPECT_TRUE(test.c_str()[0] == '\0');
    EXPECT_TRUE(test.length() == 0);
    EXPECT_TRUE(test.capacity() == 1);

    // test of non default constructor
    myString text("a character sequence");
    char test2[] = "a character sequence";
    bool check=true;
    if (text.length()!= 20){
	check=false;
    } else {
	for (int i=0; i<20;++i){
	  if(text.c_str()[i]!=test2[i]){
		check=false;
		break;
	  }
	}
    }
    EXPECT_TRUE(check);

    // test different methods
    EXPECT_TRUE(text.length() == 20);
    EXPECT_TRUE(text.max_size() == 100);
    EXPECT_TRUE(text.capacity() == 21);

    // empty string
    myString empty("");
    EXPECT_TRUE(empty.empty() == 1);

    // test method reserve
    text.reserve(30);
    EXPECT_TRUE(text.capacity() == 30);
    text.reserve(5);
    EXPECT_FALSE(text.capacity() == 5);

    //modified text string with operator =
    text="a new character sequence";
    char test3[] = "a new character sequence";
    EXPECT_TRUE(text.c_str()[0] == test3[0]);
    EXPECT_TRUE(text.c_str()[22] == test3[22]);

    EXPECT_TRUE(text.length() == 24);
    EXPECT_TRUE(text.max_size() == 100);
    EXPECT_TRUE(text.capacity() == 25);


    //std::cout << "test de l'addition : " << (text+test).c_str() << std::endl;

    // test of method resize
    // n < len and c = ' '
    myString s1("julie");
    size_t n = 3;
    s1.resize(n,' ');

    EXPECT_TRUE(s1.c_str()[2] == 'l');
    EXPECT_TRUE(s1.length() == 3);

    // n > len and c = 'a'
    myString s2("julie");
    size_t n2 = 10;
    s2.resize(n2,'a');
    EXPECT_TRUE(s2.c_str()[9] == 'a');
    EXPECT_TRUE(s2.length() == 10);

    // n > len and c = ' '
    myString s3("julie");
    size_t n3 = 10;
    s3.resize(n3,'\0');
    // revoir comment �crire un caract�re vide :
    //EXPECT_TRUE(s3.c_str()[8] == ' ');
    EXPECT_TRUE(s3.length() == 10);

    // n = len and c = ' '
    myString s4("julie");
    size_t n4 = 5;
    s4.resize(n4,'\0');
    EXPECT_TRUE(s4.c_str()[4] == 'e');
    EXPECT_TRUE(s4.length() == 5);

    // n > max_size
    // should have an output "size is too large, string overflow"
    // nothing is changed on the string
    myString s5("julie");
    size_t n5 = 101;
    s5.resize(n5,'a');
    EXPECT_TRUE(s5.c_str()[4] == 'e');
    EXPECT_TRUE(s5.length() == 5);

    // n = 0
    myString s6("julie");
    size_t n6 = 0;
    s6.resize(n6,'a');
    EXPECT_TRUE(s6.c_str()[0] == '\0');
    EXPECT_TRUE(s6.length() == 0);

    // test operator =
    myString s7("jb");
    myString s8("laura");
    EXPECT_TRUE(s7.c_str()[0] == 'j');
    s7 = s8;
    EXPECT_TRUE(s7.c_str()[0] == 'l');
    EXPECT_TRUE(s7.c_str()[4] == 'a');
    EXPECT_TRUE(s7.length() == 5);
    EXPECT_TRUE(s7.capacity() == 6);

    // test operator +
    myString s9("coucou");
    myString s10 = s9 + '!';
    EXPECT_TRUE(s10.c_str()[0] == 'c');
    EXPECT_TRUE(s10.c_str()[6] == '!');

}

