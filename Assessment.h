#ifndef ASM_H
#define ASM_H
#include <iostream>
using namespace std;
class Assessment
{
	virtual void CalculateGrade()=0;
protected:
	char grade;
public:
	Assessment(char='F');
	virtual ~Assessment(){}
	virtual void Report()=0;
	friend ostream& operator<<(ostream&,Assessment&);
};
#endif
