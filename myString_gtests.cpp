#include "gtest/gtest.h"
#include "myString.cpp"
#include <stdlib.h> // used for size_t

// A REVOIR : on teste des méthodes aussi donc je ne sais pas si on peut tester le constructeur comme ça
// g-test of default constructor
TEST(GTestTests, defaultconstructorTest) {
    myString test;
    EXPECT_TRUE(test.c_str()[0] == '\0');
    EXPECT_TRUE(test.length() == 0);
    EXPECT_TRUE(test.capacity() == 1);
};

// g-test of c-string constructor
TEST(GTestTests, cstringconstructorTest) {
    myString text("a character sequence");
    EXPECT_STREQ(text.c_str(), "a character sequence");
};


TEST(GTestTests, emptystringTest) {
    myString empty("");
    EXPECT_TRUE(empty.empty() == 1);
};

// g-test method reserve
TEST(GTestTests, reserveTest) {
    myString text("a character sequence");
    text.reserve(30);
    EXPECT_TRUE(text.capacity() == 30);
    text.reserve(5);
    EXPECT_FALSE(text.capacity() == 5);
};


TEST(GTestTests, operatorequalaffectTest) {
    //modified text string with operator =
    myString text("a character sequence");
    text="a new character sequence";
    EXPECT_STREQ(text.c_str(), "a new character sequence");
    EXPECT_TRUE(text.length() == 24);
    EXPECT_TRUE(text.capacity() == 25);

};

// A COMPLETER
TEST(GTestTests, operatorplusaddedTest) {
    //std::cout << "test de l'addition : " << (text+test).c_str() << std::endl;
};


TEST(GTestTests, lengthTest) {
    myString test;
    EXPECT_TRUE(test.length() == 0);

    myString text("a character sequence");
    EXPECT_TRUE(text.length() == 20);

};


TEST(GTestTests, maxsizeTest) {
    myString test;
    EXPECT_TRUE(test.max_size() == 100);
    myString text("a character sequence");
    EXPECT_TRUE(text.max_size() == 100);

};


// gtest of method resize
TEST(GTestTests, resizeTest) {
    // n < len and c = ' '
    myString s1("julie");
    size_t n = 3;
    s1.resize(n,' ');
    EXPECT_STREQ(s1.c_str(), "jul");
    EXPECT_TRUE(s1.c_str()[3] == '\0');
    EXPECT_TRUE(s1.length() == 3);
    EXPECT_TRUE(s1.capacity() == 4);

    // n > len and c = 'a'
    myString s2("julie");
    size_t n2 = 10;
    s2.resize(n2,'a');
    EXPECT_STREQ(s2.c_str(), "julieaaaaa");
    EXPECT_TRUE(s2.length() == 10);
    EXPECT_TRUE(s2.capacity() == 11);

    // n > len and c = '\0'
    myString s3("julie");
    size_t n3 = 10;
    s3.resize(n3,'\0');
    EXPECT_STREQ(s3.c_str(), "julie");
    EXPECT_TRUE(s3.c_str()[5] == '\0');
    EXPECT_TRUE(s3.c_str()[8] == '\0');
    EXPECT_TRUE(s3.length() == 10);
    EXPECT_TRUE(s3.capacity() == 11);

    // n = len and c = '\0'
    myString s4("julie");
    size_t n4 = 5;
    s4.resize(n4,'\0');
    EXPECT_STREQ(s4.c_str(), "julie");
    EXPECT_TRUE(s4.length() == 5);
    EXPECT_TRUE(s4.capacity() == 6);

    // n > max_size
    // nothing is changed on the string
    myString s5("julie");
    size_t n5 = 101;
    s5.resize(n5,'a');
    EXPECT_STREQ(s5.c_str(), "julie");
    EXPECT_TRUE(s5.length() == 5);
    EXPECT_TRUE(s5.capacity() == 6);

    // n = 0
    myString s6("julie");
    size_t n6 = 0;
    s6.resize(n6,'a');
    EXPECT_TRUE(s6.c_str()[0] == '\0');
    EXPECT_TRUE(s6.length() == 0);
    EXPECT_TRUE(s6.capacity() == 1);

};


TEST(GTestTests, operatorplusTest) {
    // test operator +
    myString s1("coucou");
    myString s2 = s1 + '!';
    EXPECT_STREQ(s2.c_str(), "coucou!");
};


TEST(GTestTests, operatorequalTest) {
    // right string longer than left string
    myString s1("jb");
    myString s2("laura");
    EXPECT_STREQ(s1.c_str(), "jb");
    s1 = s2;
    EXPECT_STREQ(s1.c_str(), "laura");
    EXPECT_TRUE(s1.length() == 5);
    EXPECT_TRUE(s1.capacity() == 6);

    // left string longer than right string
    myString s3("jb");
    myString s4("laura");
    EXPECT_STREQ(s3.c_str(), "jb");
    s4 = s3;
    EXPECT_STREQ(s4.c_str(), "jb");
    EXPECT_TRUE(s4.length() == 2);
    EXPECT_TRUE(s4.capacity() == 3);

    // empty string
    myString empty("");
    myString s5("not empty");
    empty = s5;
    EXPECT_STREQ(empty.c_str(), "not empty");
    s5 = empty;
    EXPECT_STREQ(s5.c_str(), empty.c_str());
};
