/*******************************************************************************************************************************************************
Filename	:		Name.cpp
Version		:		1
Author		: 		Lovejot Singh	Dew
Student No	:		040716354
Course Name/Number:	C++
Assingment 	:		3
Assignment Name :	Student Database
Due Date 	:		7/December/2013
Professor	:		Andrew Tyler
Purpose		:		The name class creates space thats is required to hold the strings of firstName and lastName that is given by the user
					it calculates the space required and allocates the memeory for the specific string.

********************************************************************************************************************************************************/
#include "Name.h"
/*******************************************************************************************************************************************************
Function Name:		Name()
Purpose:			Initializes the firstName and lastName pointers to NULL
In Parameters:		None
out parameters:		NONE
Version:			2
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
Name::Name(){
	firstName=NULL;	//giving pointers a null value 
	lastName=NULL;
}
/*******************************************************************************************************************************************************
Function Name:		Name(char*, char*)
Purpose:			 constructor with parameters , assigns the pointers in the parameters to the firstname and lastName calculating exact space needed
					for each one of them.Also adds \0 in the end to make it a C_type string.
In Parameters:		char * pointer to the firstname and char * a pointer to lastname
out parameters:		NONE
Version:			2
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
Name::Name(char* fName, char* lName){
	int fnLength=strlen(fName);	//calculating length for firstname
	int lnLength=strlen(lName); //calc length for lastname 

	firstName= new char[fnLength+1]; // allocating memory to hold strings
	lastName= new char[lnLength+1];	// allocating memory to hold strings

	strncpy(firstName,fName,fnLength+1);	//tranfering strings from parameter to the memory 
	strncpy(lastName,lName,lnLength+1);		//tranfering strings from parameter to the memory 
}
/*******************************************************************************************************************************************************
Function Name:		Name(Name&)
Purpose:			Overload constructor takes name object as parameter , the name object might have two strings consisting of firstname and
					lastname or they might be empty as well. If there are strings in the object this function calculates the space required
					and allocates memory to the pointer and copies the strings into those.
In Parameters:		Object of type Name
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
Name::Name(Name& n){
	if(strlen(n.firstName)>0){		//if its an empty string we don't need to allocate space for it 
	firstName= new char[strlen(n.firstName)+1];	// allocate memory for firstname 
	strncpy(firstName,n.firstName,strlen(n.firstName));		// copy chars from parameter to memory allocated
	
	lastName= new char [strlen(n.lastName)+1];
	strncpy(firstName,n.lastName,strlen(n.lastName));
	}

}
/*******************************************************************************************************************************************************
Function Name:		Operator=(Name&); Overload assignment operator
Purpose:			the function takes an object of type name and compares it to see the already existing name object is same , if yes then returns the same object back
					else it checks for pointer firstname and lastname to be empty .If not it deletes what ever is there in memory and reallocates memmory for 
					the new strings passed in with Name object.(this) is the object on the leftside of = operator that is being assigned the value of 
					Name obejct N which is a right side object.
In Parameters:		Object of N 
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
*******************************************************************************************************************************************************/
Name& Name::operator=(Name& N){

	if((this->firstName == N.firstName)&&(this->lastName== N.lastName)){return *this;} //if the user supplied same name we donot need to allocate memory again return the same 

	if(this->firstName){
		delete [] firstName;	//if LHS object already contains somethings in memory remove it 
		this->firstName=NULL;						// to avoid garbage 
	}										
	if(this->lastName){
		delete []lastName;
		this->lastName=NULL;
	}

	if(N.firstName!=NULL){										// if empty string is passed we don't need to do anything skip it
	int flength=strlen(N.firstName);							// calc space for firstname 
	int llength=strlen(N.lastName);
	this->firstName=new char[flength+1];						//allocate memory to first name
	this->lastName=new char[llength+1];
	strncpy(this->firstName,N.firstName,strlen(N.firstName));	// copy stirngs from RHS object to LHS object 
	firstName[flength]='\0';									//just an extra measure to make it C_type string
	strncpy(this->lastName,N.lastName,strlen(N.lastName));
	lastName[llength]='\0';
	}	
	return *this;												//returning object of type name
}
/*******************************************************************************************************************************************************
Function Name:		Operator==(Name&)
Purpose:			Overload equalsto(==) operator take an object of type name as parameter. The funtion tries to compares the values of the object on leftside of the 
					== operator to the object on right side of the operator if they are equal it returns true or else it returns false.
In Parameters:		Object of N 
out parameters:		true or false . true if both the objects have same elemental values.
Version:			1
Author:				Lovejot Singh	
*******************************************************************************************************************************************************/
bool Name::operator==(Name& N){
	if(this->lastName!=NULL && this->firstName!=NULL){		//we don't need to waste time comparing something to nothing
		if(strcmp(this->lastName,N.lastName)==0){			//calculating differences if any
			if(strcmp(this->firstName,N.firstName)==0)
			return true;
		}//end of strcmp
	}
	return false ; 
}
/*****************************************************************************************************************************************************
Function Name:		Operator>(Name&)
Purpose:			Overload greater than(>) operator takes an object of type name as parameter. The funtion tries to compares the values of the object on leftside of the 
					> operator to the object on right side of the operator if the LHS object is greater than RHS object it returns true or else it returns false.

In Parameters:		Object of N 
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
*******************************************************************************************************************************************************/
bool Name::operator>(Name& N){
	if(this->lastName!=NULL){		//no need to waste time comparing something to nothing
		if(strcmp(this->lastName,N.lastName)>0){		//return true if this->lastname is greater tha N.lastName
				return true;
		}
	}
	 return false;									
}
/*******************************************************************************************************************************************************
Function Name:		 operator<(Name&)
Purpose:			Overload  less-than(>) operator takes an object of type name as parameter. The funtion tries to compares the values of the object on leftside of the 
					> operator to the object on right side of the operator if the LHS object is smaller than RHS object it returns true or else it returns false.

In Parameters:		Object of N 
out parameters:		return true on success and false on failure
Version:			1
Author:				Lovejot Singh	
*******************************************************************************************************************************************************/
bool Name::operator<(Name& N){
	if(strcmp(this->lastName,N.lastName)<0){		
		return true;
	}
	else return false;
}

/*******************************************************************************************************************************************************
Function Name:		 ~Name()
Purpose:			destroy object and memory allocated to the object. 
In Parameters:		Object of N 
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
*******************************************************************************************************************************************************/
Name::~Name(){
	if(firstName!=NULL){	
		delete []firstName;
		firstName=NULL;		// delete only if there is something to delete
	}
	if(lastName!=NULL){ delete []lastName;		// delete only if there is something to delete
	lastName=NULL;
	}
}
/*******************************************************************************************************************************************************
Function Name:		operator<<(ostream& , Name& ) 
Purpose:			overloading << operator . takes an object and prints the elements of the object using an object of class ostream
In Parameters:		ostream& the object works like (cout) 
					Name & nam contains string to be printed
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
*******************************************************************************************************************************************************/
ostream & operator <<(ostream& os , Name& nam){
	os<<nam.firstName << " " << nam.lastName;		
	return os;
}
/***********************************************************END OF FILE*********************************************************************************
*******************************************************************************************************************************************************/
