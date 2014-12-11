#ifndef Name_H
#define Name_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Name
{
	char* firstName;
	char* lastName;
public:
	Name();
	Name(char*,char*);
	Name(Name&);
	~Name();
	Name& operator=(Name&);
	bool operator==(Name&);			
	bool operator>(Name&);			
	bool operator<(Name&);			
	friend ostream& operator<<(ostream&, Name&);	//output function=
};
#endif
