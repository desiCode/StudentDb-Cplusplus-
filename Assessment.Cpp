/*******************************************************************************************************************************************************
Filename	:		Assessment.cpp
Version		:		1
Author		: 		Lovejot Singh	Dew
Student No	:		040716354
Course Name/Number:	C++
Assingment 	:		3
Assignment Name :	Student Database3
Due Date 	:		7/December/2013
Professor	:		Andrew Tyler
Purpose		:	This class creates virtual functions in the header file that all the classes that inherit this class must have those function 
				in order to impliment pure polymorphism

********************************************************************************************************************************************************/
#include "Assessment.h"
/*******************************************************************************************************************************************************
Function Name:		Assessment()
Purpose:			Constructor with parameter
In Parameters:		n_grade
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
Assessment::Assessment(char n_grade){
	grade=n_grade;
}
/*******************************************************************************************************************************************************
Function Name:		operatoros()
Purpose:			does nothing
In Parameters:		NONE
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
ostream & operator <<(ostream& os , Assessment& A){
	return os;
}
