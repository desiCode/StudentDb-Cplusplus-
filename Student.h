#ifndef Student_H
#define Student_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"Comment.h"
#include"Name.h"
#include "Course.h"
#include "Assessment.h"
#include"PLAAssessment.h"
#include"ExamAssessment.h"
#include"ProjectAssessment.h"

using namespace std;
class Student
{
	Name name;
	Comment comment;
	int	ID;		// -1 when unfilled. 
	Course** courses;
	unsigned int numCourses;
	void AddCourse(); // Add  a new course
public:
	Student();// default constructor - arrays of students have an id of -1
	Student(char*,char*,char*,int);	// firstName,lastName,comment,ID,fee
	Student& operator=(Student&);	// assign a Student
	bool operator==(Student&);	// has same first and last name?
	bool operator>(Student&);	// greater last name?
	bool operator<(Student&);	// smaller last name?
	int GetID();
	void EditStudent();
	friend ostream& operator<<(ostream&,Student&);
	~Student();
};
#endif
