#ifndef DBManager_H
#define DBManager_H
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Student.h"
using namespace std;
class DBManager
{
	static const unsigned int max = 1000;
	Student Students[max];
public:
	bool b_running;
	DBManager();
	bool AddNewStudent();
	bool DeleteStudent();
	bool EditStudent();
	bool ReportStudents();
	bool ReportStudentsOrdered();
};
#endif
