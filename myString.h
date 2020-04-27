#include <stdlib.h> // for size_t

class myString{
	public :
	myString(); //default constructor
    const char* c_str() const;//returns the string's array without allowing any modification
    myString(const char* s);//constructor using a C style string
	~myString(); //destructor

	size_t capacity(); //returns cap
	bool empty(); //returns true if the string stored is the emty string
	void reserve(size_t n); //If n is greater than the actual capacity, increase the capacity of the string's array to n
	myString& operator= (const char* s); //copy the content of the given C style string into the string's array
	myString operator+(const myString& added);; //Create a new string with the content of the 2 given strings

    size_t length()const; //returns len
	size_t max_size(); //returns the maximum length that the string can reach
	void resize(size_t n, char c='\0'); // Resizes the string to a length of n characters. If n<len  the string is shortened to his first n characters, if n>=len add to the string the character c (n-len) times.

	myString& operator= (const myString& str); //copy the given string
	myString operator+ (char rhs); //add the given char at the end of the string's array

	private :
		char *content; //Adress of the first cell of the array storing the string
		size_t len; //Length of the string without the '\0' character
		size_t cap; //Size of the array storing the string
};
