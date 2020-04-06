class myString{
	public :
		myString();

        char* affiche();
        myString(const char* s);
	~myString();


	private :
		char *content;
		int length;
};
