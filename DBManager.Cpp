/*******************************************************************************************************************************************************
Filename	:		DBManager.cpp
Version		:		1
Author		: 		Lovejot Singh	Dew
Student No	:		040716354
Course Name/Number:	C++
Assingment 	:		2
Assignment Name :	Student Database
Due Date 	:		9/November/2013
Professor	:		Andrew Tyler
Purpose		:		Until the user quits ,it reads an option selected by the user and then performs addition , deletion , editing and viewing of the student database.When ever a
                    student is added to the database it is given the highest ID no.
********************************************************************************************************************************************************/
#include "DBManager.h"
/*******************************************************************************************************************************************************
Function Name:		DBManager()
Purpose:			default constructor does more or less nothing
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
DBManager::DBManager(){
}
/*******************************************************************************************************************************************************
Function Name:		AddNewStudent()
Purpose:			takes firstname , lastname , comment and fee from the user and add the student to the first available index of the array with id one 
					greater than of a student before. For the first student it gives an id of 0 .
In Parameters:		None
out parameters:		return true
Version:			3
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
bool DBManager::AddNewStudent(){

	int index,
		loop,
		tempID=-1;	//index used to find first available ,loop  used in for loop , tempID is used to find the highest id of the array
	float fee=0;				// fee used to take user input		
	char fName[25];				// temporary array of chars to hold firtname
	char lName[25];				//temporary array of chars to hold lastname
	char tcomment[1000];		//temporary array of chars to hold comment
	bool labhgea=false;			// labhgea is used to check if there is an empty slot in an array or not	

	for(loop=0;loop<max;loop++){			//for loop to find the available index to add new student
		if(Students[loop].GetID()==-1 && !labhgea ){	// && !labhgea is used to make sure we add student at first available space in the array
		labhgea=true;						//space found go true
		index=loop;							// index found 
		}	
	}
	tempID=-1;					
	for(int mas=0;mas<max;++mas){			//for loop to find the highest ID of the array 
		if(tempID < Students[mas].GetID()){ 
			tempID=Students[mas].GetID();
		}
	}
	++tempID;								//increase the id 
	if(labhgea == false){					// if no empty slot available 
		cout<<"Database is already full !!"<<endl;
		return true;
	}

	// take inputs from the user 
	cout<<"Please enter the new student first name (e.g. Barrack): ";
	cin>>fName;
	cout<<"Please enter the new student last name (e.g. Obama): ";
	cin>>lName;
	cout<<"Please enter the comment ( 1000 characters max ): ";
	cin.ignore();
	cin.getline(tcomment,sizeof(tcomment));

	Students[index]=Student(fName,lName,tcomment,tempID);		//using overloaded assignment operator to assign the value 
	return true;
}
/*******************************************************************************************************************************************************
Function Name:		DeleteStudent()
Purpose:			delete a student
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
bool DBManager::DeleteStudent(){
	int id ;													//temporary int to store user input
	bool found=false;											// to check if user enter id was matched
	cout<<"Please enter the id of the student to delete ";		
	cin>>id;													
	for(int loop=0; loop <max ;loop++){							//for loop to find student of the id enter by user
		if(Students[loop].GetID()==id){
				Students[loop]=Student("","","",-1);		// change id to -1 set it out of scope
			
			found=true;
				cout<<"Student Deleted !\n"<<endl;
				return true;
		}
	}
	if(!found){cout<<"Student not found ! Please try again with correct ID !\n";}		//if the id didn't match let the user Know
	return true;
}
/*******************************************************************************************************************************************************
Function Name:		EditStudent()
Purpose:			take firstname and lastname of the student from the user to edit if the student is found edit the student else give a message 
					student not found
In Parameters:		None
out parameters:		NONE
Version:			4
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
bool DBManager::EditStudent(){

	char fName[25];
	char lName[20];
	cout<<"Edit Student"<<endl;
	cout<<"Please enter the first name of the student to edit (e.g. Barack)";		
	cin>>fName;
	cout<<"Please enter the last name of the student to edit (e.g. Barack)";
	cin>>lName;
	Student stud= Student(fName,lName,"",-1);			//creating a temp object of Student class to use == operator
	bool found=false;										// found bool to check if the student was found


	for(int loop=0;loop<max;loop++){						// for loop to check if the name given by the user was found in the database
		if(Students[loop].GetID() != -1)
		if((stud == Students[loop])){				//using overlaoded eqaulsto operator
			found= true;
			cout<<"Student Found  with name ";
			cout<<fName <<" "<< lName << endl;
			cout<<"Editing Name: ";
			cout << fName<<" "<<lName<<endl;		
			Students[loop].EditStudent();						//calling edit function related to the student object
			break;
		}
	}
	if(!found){					//if the name was not found in the database let the user know 
		cout<<"Student not Found !\n";
		return true;
	}
	
	return true;
}
/*******************************************************************************************************************************************************
Function Name:		ReportStudents()
Purpose:			prints student in the database
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
bool DBManager::ReportStudents(){			
	bool found=false;					// found boolean to see if there is student in the database to print
	for(int loop=0;loop<max;loop++){	// for loop to print students with id greater than -1 
		if(Students[loop].GetID()!=-1){
			found=true;
			cout<<Students[loop];				// using the overloaded << operator to print student elements
		}
	}
	if(!found){cout<<"Database is empty !\n";}
	return true;
}
/******************************************************************************************************************************************************
Function Name:		ReportStudentsOrdered()
Purpose:			Prints the students in alphabetic order of their last name
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
bool DBManager::ReportStudentsOrdered(){
	bool notempty=false;
	Student temp= Student();
	int studs=0; // total number of students in the database
	for(int loop=0;loop<max;loop++){
		if(Students[loop].GetID()!=-1){
			studs=loop;				//maximum number of studs in database
			notempty=true; // the database in not emtpy
		}
	}
	if(notempty){		// the database is not empty
		bool swap=false;			// swap boolean to keep track of swaping taking place in buble sort
		Student buble[max+1];			// temp buble array to hold student for buble sorting
		for(int loop =0;loop<=studs;loop++){		//for loop to copy array
			buble[loop]=Students[loop];				//assigning array by index
		}

		while(swap!=true){							//while the array is not swaped

				swap=true;							//set boolean value to true
			for(int loop=0;loop<studs;loop++){
			//buble sort algorithm
				if(buble[loop+1].GetID() !=-1)
				if(buble[loop] > buble[loop+1] ){

					temp=buble[loop+1];
					buble[loop+1]=buble[loop];
					buble[loop]=temp;
					swap=false;						//swap occured turn boolean to false and let the loop run once again
			}
		}
	}
		//printing students order by last name
		for(int loop=0;loop<=studs;loop++){
			if(buble[loop].GetID()!=-1)
			cout<<buble[loop];
		}
	}
	else {
		cout<<"Database is empty ! "<<endl;
	}
	return true;
}


/*******************************************************************************************************************************************************
														END OF FILE
********************************************************************************************************************************************************/
