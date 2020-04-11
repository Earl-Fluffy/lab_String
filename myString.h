class myString{
	public :
	myString();
        char* affiche();
        myString(const char* s);
	~myString();
        int length();
	int capacity();


	private :
		char *content;
		int len;
		int cap;
};
