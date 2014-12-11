
#ifndef Course_H
#define Course_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Assessment.h"
#include"PLAAssessment.h"
#include"ExamAssessment.h"
#include"ProjectAssessment.h"
using namespace std;

class Course
{	
	char* courseName;
	float fee;
	Assessment* assessment;
public:
	Course();
	Course(Course&);
	Course(char*,float,Assessment*);	//name,fee,assessment
	~Course();
	friend ostream& operator<<(ostream& os, Course&);
};


#endif
