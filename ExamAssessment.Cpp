/*******************************************************************************************************************************************************
Filename	:		ExamAssessment.cpp
Version		:		1
Author		: 		Lovejot Singh	Dew
Student No	:		040716354
Course Name/Number:	C++
Assingment 	:		3
Assignment Name :	Student Database3
Due Date 	:		7/December/2013
Professor	:		Andrew Tyler
Purpose		:	This class is inherited from class Assessment using the pure polymorphic rules.
				It takes in integer value as examMark and calcualtes grade relating to the mark and assigns it the objet of this class

********************************************************************************************************************************************************/
#include "ExamAssessment.h"
/*******************************************************************************************************************************************************
Function Name:		ExamAssessment()
Purpose:			Constructor with parameters
In Parameters:		float Mark
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
ExamAssessment::ExamAssessment(float mark):examMark(mark){
	CalculateGrade();
}
/*******************************************************************************************************************************************************
Function Name:		ExamAssessment()
Purpose:			copy constructor 
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
ExamAssessment::ExamAssessment(ExamAssessment& exam_A):examMark(exam_A.examMark){
	examMark= exam_A.examMark;
	CalculateGrade();
}
/*******************************************************************************************************************************************************
Function Name:		CalculateGrade()
Purpose:			to calculate the grade of type char depending on the variable examMark of type int  
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
void ExamAssessment::CalculateGrade(){
	if(examMark <= 50 && examMark >0 ){
		grade='F';
	}
	else if(examMark >= 50 && examMark < 60  ){
		grade = 'D';
	}
	else if(examMark >= 60 && examMark < 70 ){
		grade='C';
	}
	else if(examMark >= 70 && examMark < 80 ){
		grade = 'B';
	}
	else if(examMark >= 80 && examMark < 100 ){
		grade = 'A';
	}
}
/*******************************************************************************************************************************************************
Function Name:		Report()
Purpose:			Initializes the comment 
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
void ExamAssessment::Report(){
	cout<<"Type: Exam "<<endl;
	cout<<"Course Grade= "<<this->grade<<endl<<endl;
}
/*******************************************************************************************************************************************************
									END OF PROGRAM	
********************************************************************************************************************************************************/
