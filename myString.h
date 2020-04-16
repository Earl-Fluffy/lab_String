#include <stdlib.h> // pour size_t

class myString{
	public :
	myString();
        char* affiche();
        myString(const char* s);
	~myString();
        int length();
	int capacity();
	bool empty();
	void reserve(int n);
	void operator= (const char* s);
	myString operator+( myString added);

	int max_size();
	void resize(size_t n, char c);
	myString& operator= (const myString& str);

	private :
		char *content;
		int len;
		int cap;
};
