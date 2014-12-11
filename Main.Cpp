#define _CRTDBG_MAP_ALLOC

#include "Comment.h"
#include "Name.h"
#include "Assessment.h"
#include "ExamAssessment.h"
#include "PLAAssessment.h"
#include "ProjectAssessment.h"
#include "Course.h"
#include "Student.h"
#include "DBManager.h"

#include <iostream>
using namespace std;

int main(void)
{
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	int i_response;
	DBManager dbmanager;

 	while(dbmanager.b_running)
	{
		cout<<"\nPlease enter your choice\n";
		cout<<"1. Add a new student\n";
		cout<<"2. Delete a student\n";
		cout<<"3. Edit a student\n";
		cout<<"4. Report Students\n";
		cout<<"5. Report Students Ordered\n";
		cout<<"6. Quit\n";

		cin>>i_response;
		switch(i_response)
		{
		case 1:
			if(!dbmanager.AddNewStudent())
				return 1;
			break;
		case 2:
			if(!dbmanager.DeleteStudent())
				return 1;
			break;
		case 3:
			if(!dbmanager.EditStudent())
				return 1;
			break;
		case 4:
			if(!dbmanager.ReportStudents())
				return 1;
			break;
		case 5:
			if(!dbmanager.ReportStudentsOrdered())
				return 1;
			break;
		case 6:
			dbmanager.b_running = false;
			break;
		default: 
			cout<<"Please enter a valid choice"<<endl;
		}
	}
	return 0;
}

