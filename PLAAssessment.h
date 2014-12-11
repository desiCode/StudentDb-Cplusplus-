#ifndef PLAA_H
#define PLAA_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Assessment.h"
using namespace std;

class PLAAssessment:public Assessment
{
	char PLAGrade;
	void CalculateGrade();
public:
	PLAAssessment(char='F');
	PLAAssessment(PLAAssessment&);
	void Report();
};

#endif
