/*******************************************************************************************************************************************************
Filename	:		Comment.cpp
Version		:		1
Author		: 		Lovejot Singh	Dew
Student No	:		040716354
Course Name/Number:	C++
Assingment 	:		2
Assignment Name :	Student Database
Due Date 	:		9/November/2013
Professor	:		Andrew Tyler
Purpose		:		The comment class calculates space required by the comment string entered by the user and then allocates memory to it 
********************************************************************************************************************************************************/
#include "Comment.h"
/*******************************************************************************************************************************************************
Function Name:		Comment()
Purpose:			Initializes the comment 
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
Comment::Comment(){
	comment=NULL;
}
/*******************************************************************************************************************************************************
Function Name:		Comment(char*)
Purpose:			Copy constructor 
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
Comment::Comment(char* com){
	int length=strlen(com);				//calculating length for comment
	comment= new char[strlen(com)+1];	//allocating space for comment
	strncpy(comment,com,length);		//copying string to memory allocated
	comment[length]='\0';				//extra measure to make it a C_type string
}
/*******************************************************************************************************************************************************
Function Name:		Comment(Comment&)
Purpose:			takes an object of type comment that contains a string holding comment as an element calculate space for it allocate it and copy it
					to the memory
In Parameters:		obejct of type Comment
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
Comment::Comment(Comment& copy){			
	int len= strlen(copy.comment);			//calcuating space
	comment= new char[len+1];				//allocating space
	strncpy(comment,copy.comment,len);		//copying string to allocated space
}
/*******************************************************************************************************************************************************
Function Name:		~Comment()
Purpose:			destructs the memory allocated to comment
In Parameters:		None
out parameters:		NONE
Version:			2
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
Comment::~Comment(){
	if(comment!=NULL){			// delete only if there is something to delete
		delete []comment;
	}
}
/*******************************************************************************************************************************************************
Function Name:		operator=()
Purpose:			Overload assignment operator ()
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
Comment& Comment::operator=(Comment& com){

	if(this->comment == com.comment){return *this;} //a check to see if its the same comment no need to waste machine cycles
	else{
		if(this->comment){		//if previous comment is there delete it
			delete [] comment;
			this->comment=NULL;		// set the pointer to null
		}


		int length=strlen(com.comment);		//calculate space 
		this->comment= new char [length+1];		//allocating required space
		strncpy(this->comment,com.comment,length);		// copying string to allocated space
		this->comment[length]='\0';					//extra measure to make it a C_type String
	}
	return * this;
}
/*******************************************************************************************************************************************************
Function Name:		operator<<(ostream& , Comment&)
Purpose:			Overload <<operator () to print the elements of object
In Parameters:		os object of type ostream	
					com object of type Comment
out parameters:		os object of class ostream that prints the data 
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
ostream& operator<<(ostream& os ,Comment& com){
	os << com.comment<<endl;
	return os;
}

/*******************************************************************************************************************************************************
************************************************************END OF FILE**********************************************************************************/
