/*******************************************************************************************************************************************************
Filename	:		Course.cpp
Version		:		1
Author		: 		Lovejot Singh	Dew
Student No	:		040716354
Course Name/Number:	C++
Assingment 	:		3
Assignment Name :	Student Database3
Due Date 	:		7/December/2013
Professor	:		Andrew Tyler
Purpose		:	Course class handles object of type Course and function related to them 
				adding a course with different type of assessments to it. 

********************************************************************************************************************************************************/
#include "Course.h"
/*******************************************************************************************************************************************************
Function Name:		Course()
Purpose:			Initializes the id to -1 , fee to 0.0
In Parameters:		None
out parameters:		NONE
Version:			2
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
Course::Course(){
	courseName =NULL;
	fee=0.0f;
	assessment=NULL;
}
/*******************************************************************************************************************************************************
Function Name:		Course()
Purpose:			constructor with parameters used to iniatilize members of the class with the passed parameters 
In Parameters:		None
out parameters:		NONE
Version:			2
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
Course::Course(char* cName , float nFee,Assessment * ast){
	int c_length= strlen(cName);
	if(c_length >0) {
		courseName = new char[c_length+1];				// doing same stuff as done in Name.cpp so not commenting old stuff
		strncpy(courseName, cName,c_length);
		courseName[c_length]='\0';
	}
	fee= nFee;
	assessment=ast;
}
/*******************************************************************************************************************************************************
Function Name:		Course()
Purpose:			copy constructor that copies the members of one incoming parameter to existing member 
In Parameters:		object of type Course
out parameters:		NONE
Version:			2
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
Course::Course(Course &i){
	if(strlen(i.courseName)>0){
		courseName= new char[strlen(i.courseName)+1];
		strncpy(courseName,i.courseName,strlen(i.courseName)+1);
		fee=i.fee;
		

		if (dynamic_cast<ExamAssessment*>(i.assessment) != 0) {		//using dynamic cast to check what type of assessment is it
			assessment = new ExamAssessment(*static_cast<ExamAssessment*>(i.assessment));
		}
		else if (dynamic_cast<PLAAssessment*>(i.assessment) != 0) {
			assessment = new PLAAssessment(*static_cast<PLAAssessment*>(i.assessment));
		}
		else if (dynamic_cast<ProjectAssessment*>(i.assessment) != 0) {
			assessment = new ProjectAssessment(*static_cast<ProjectAssessment*>(i.assessment));
		}
	}	
}
/*******************************************************************************************************************************************************
Function Name:		~Course()
Purpose:			deleting all dynamic memory allocated in the process
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
Course::~Course(){
	if(courseName != NULL){
		delete []courseName;
	}
	if(assessment!= NULL){
		delete []assessment;
	}
}
/*******************************************************************************************************************************************************
Function Name:		operator<<()
Purpose:			overloaded operator used to print the members of the object
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/

ostream & operator<<(ostream& os , Course& cs){
	
	os<<"Course Name:"<<cs.courseName<<endl;
	os<<"fee = "<<cs.fee<<endl;
	cs.assessment->Report();
	
	return os;
}

/*******************************************************************************************************************************************************
********************************************************************************************************************************************************/
