#ifndef ProjectA_H
#define ProjectA_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Comment.h"
#include "Assessment.h"

class ProjectAssessment:public Assessment
{
	Comment projectTitle;
	float projectMark;
	void CalculateGrade();
public:
	ProjectAssessment(char* = "",float=0.0);
	ProjectAssessment(ProjectAssessment&);
	void Report();
};
#endif
