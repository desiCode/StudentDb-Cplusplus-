/*******************************************************************************************************************************************************
Filename	:		ProjectAssessment.cpp
Version		:		1
Author		: 		Lovejot Singh	Dew
Student No	:		040716354
Course Name/Number:	C++
Assingment 	:		3
Assignment Name :	Student Database3
Due Date 	:		7/December/2013
Professor	:		Andrew Tyler
Purpose		:	This class is inherited from class Assessment using the pure polymorphic rules.
				It takes in an int value and calculates grade according to the number passed(which is less 100) 
				assigns it the object of this class.

********************************************************************************************************************************************************/
#include"ProjectAssessment.h"
/*******************************************************************************************************************************************************
Function Name:		CalculateGrade()
Purpose:			calculates the grade of the assessment depending on the project marks  
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
void ProjectAssessment::CalculateGrade(){
	if(projectMark < 50 ){
		grade='F';
	}
	else if(projectMark >= 50 && projectMark < 60  ){
		grade = 'D';
	}
	else if(projectMark >= 60 && projectMark < 70 ){
		grade='C';
	}
	else if(projectMark >= 70 && projectMark < 80 ){
		grade = 'B';
	}
	else if( projectMark >= 80 && projectMark < 100 ){
		grade = 'A';
	}
}
/*******************************************************************************************************************************************************
Function Name:		ProjectAssessment(char,float)
Purpose:			assign title of the project and the grade of the course
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
ProjectAssessment::ProjectAssessment(char * title,float mark):projectMark(mark){
	projectTitle =  Comment(title);
	CalculateGrade();
}
/*******************************************************************************************************************************************************
Function Name:		ProjectAssessment()
Purpose:			overloaded copy contructor initialized the object of type assessment 
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
ProjectAssessment::ProjectAssessment(ProjectAssessment& pj_A):projectMark(pj_A.projectMark){
	this->projectTitle = pj_A.projectTitle;
	CalculateGrade();
}
/*******************************************************************************************************************************************************
Function Name:		Report()
Purpose:			printing the member of the class or object
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
void ProjectAssessment::Report(){
	cout<<"Type : Project Assessment"<<endl;
	cout<<"Title: "<<this->projectTitle<<endl;
	cout<<"Course Grade: "<<this->grade<<endl<<endl;
}
/*******************************************************************************************************************************************************
									END OF ProgrAM
********************************************************************************************************************************************************/
