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


	private :
		char *content;
		int len;
		int cap;
};
