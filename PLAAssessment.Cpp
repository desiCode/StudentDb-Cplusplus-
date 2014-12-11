/*******************************************************************************************************************************************************
Filename	:		PLAAssessment.cpp
Version		:		1
Author		: 		Lovejot Singh	Dew
Student No	:		040716354
Course Name/Number:	C++
Assingment 	:		3
Assignment Name :	Student Database3
Due Date 	:		7/December/2013
Professor	:		Andrew Tyler
Purpose		:	This class is inherited from class Assessment using the pure polymorphic rules.
				It takes in char as grade assigns it the objet of this class

********************************************************************************************************************************************************/
#include "PLAAssessment.h"
/*******************************************************************************************************************************************************
Function Name:		PLAAssessment()
Purpose:			Initialize the Grade variable with n_grade using initialize list 
In Parameters:		char n_grade
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
PLAAssessment::PLAAssessment(char n_grade):PLAGrade(n_grade){
	CalculateGrade();
}
/*******************************************************************************************************************************************************
Function Name:		PLAAssessment()
Purpose:			Initializes the Grade 
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
PLAAssessment::PLAAssessment(PLAAssessment& pla):PLAGrade(pla.PLAGrade){
	CalculateGrade();
}
/*******************************************************************************************************************************************************
Function Name:		Report()
Purpose:			Printing members of the class or object
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
void PLAAssessment::Report(){
	cout<<"Type: PLAAssessment"<<endl;
	cout<<"PLA Grade: "<<this->PLAGrade<<endl;
	cout<<"Course Grade:"<<this->grade<<endl<<endl;
}
/*******************************************************************************************************************************************************
Function Name:		CalculateGrade()
Purpose:			Assigns the grade 
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
void PLAAssessment::CalculateGrade(){
	grade=PLAGrade;
}
/**********************************END OF PRogram*******************************************************************************************************
********************************************************************************************************************************************************/
