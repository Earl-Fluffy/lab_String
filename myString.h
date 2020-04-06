class myString{
	public :
		myString();

        char* affiche();
        myString(const char* s);
	~myString();
        length();


	private :
		char *content;
		int len;
};
