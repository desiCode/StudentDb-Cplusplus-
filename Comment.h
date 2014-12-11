#ifndef Comment_H
#define Comment_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Comment
{
	char* comment;
public:
	Comment();
	Comment(char*);
	Comment(Comment&);
	~Comment();
	Comment& operator=(Comment&);
	friend ostream& operator<<(ostream&,Comment&);	//output a comment 
};

#endif
