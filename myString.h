class myString{
	public :
		myString();

        char* affiche();
        myString(const char* s);
	~myString();
        int length();


	private :
		char *content;
		int len;
};
