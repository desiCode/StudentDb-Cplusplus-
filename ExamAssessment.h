#ifndef ExamAssess_H
#define ExamAssess_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Assessment.h"
class ExamAssessment:public Assessment
{
	float examMark;
public:
	ExamAssessment(float=0.0);
	ExamAssessment(ExamAssessment&);
	void CalculateGrade();
	void Report();
};
#endif
