/*******************************************************************************************************************************************************
Filename	:		Student.cpp
Version		:		1
Author		: 		Lovejot Singh	Dew
Student No	:		040716354
Course Name/Number:	C++
Assingment 	:		2
Assignment Name :	Student Database
Due Date 	:		9/November/2013
Professor	:		Andrew Tyler
Purpose		:		Student class creates objects of Name class and Comment class and send them string entered by user. It also give and id and fee elements 
					to the student object 
********************************************************************************************************************************************************/
#include "Student.h"
/*******************************************************************************************************************************************************
Function Name:		Student()
Purpose:			Initializes the id to -1 numCourset to 0 
In Parameters:		None
out parameters:		NONE
Version:			2
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
Student::Student()
{
	ID=-1;
	numCourses=0;
	name=Name();
	comment=Comment();
	courses=NULL;
}
/*******************************************************************************************************************************************************
Function Name:		Student(char*,char*,char*,int,float)
Purpose:			Initializes all the members of the database
In Parameters:		fName of type char * , lName of type char* , com of type char* , id of type int , fee of type float
out parameters:		NONE
Version:			2
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
Student::Student(char* fName,char* lName,char* comm,int id){
	name=Name(fName,lName);		//a call to name constructor
	comment=Comment(comm);		//a call to comment constructor
	ID=id;						//assigning id to ID
	numCourses =0;
}

/*******************************************************************************************************************************************************
Function Name:		operator=(Student&)
Purpose:			overload assignment operator for student class
In Parameters:		stud of type student
out parameters:		NONE
Version:			2
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
Student& Student::operator=(Student& stud){
	name = stud.name;			// assinging new string using = operator 
	comment= stud.comment;		//	assinging value using = operator
	ID= stud.ID;				//	assigning value using = operator
	//numCourses= stud.numCourses;
	

	if(this->numCourses >0){				// if we have course already delete them
		for(unsigned int loop=0;loop < numCourses ;loop++){
		delete courses[loop];			//deleting memory related to the index of the array courses
		}
		delete[]courses;			// deleting memory related to array courses
		}
	numCourses = stud.numCourses;			// assigning the num courses 

	if(stud.numCourses > 0){			// if we have courses comming in we need to allocate memory 
		courses= new Course*[this->numCourses];
		for(unsigned int loop=0;loop< stud.numCourses ; loop++){
			courses[loop] = new Course(*stud.courses[loop]);		//assigning assessments related to the student
		}
	}
	return *this;				
}	
/******************************************************************************************************************************************************
Function Name:		operator==(Student&)
Purpose:			To check if a student has same first and last name 
In Parameters:		None
out parameters:		NONE
Version:			2
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
bool Student::operator==(Student& stud){
		
	if((name == stud.name) ){	// is no difference found return 1
		return true;
	}
	else return false;
	
}	
/*******************************************************************************************************************************************************
Function Name:		operator>(Student&)
Purpose:			To check and see if the student has greater last name 
In Parameters:		None
out parameters:		NONE
Version:			2
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
bool Student::operator>(Student& stud){
	return (name > stud.name);			//returning true or false 
}	
/*******************************************************************************************************************************************************
Function Name:		Operator<()
Purpose:			take an object of type Student as a parameter and compare it to the name object to see if the student has smaller last name 
In Parameters:		stud(object) of type Student
out parameters:		return true if smaller or false is greater
Version:			2
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
bool Student::operator<(Student& stud){
	return (name < stud.name);			//returns true or false depending upon values supplied
}	
/*******************************************************************************************************************************************************
Function Name:		GetID()
Purpose:			return ID of the student
In Parameters:		None
out parameters:		ID of the student
Version:			2
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
int Student::GetID(){
	return ID;
}
/*******************************************************************************************************************************************************
Function Name:		oeprator<<(ostream& , Student&)
Purpose:			to print elements of the Student object.
In Parameters:		os of type ostream
					stud of type Student
out parameters:		NONE
Version:			2
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
ostream& operator<<(ostream&  os,Student& stud){
	os <<"Name: "<<stud.name<<endl;
	os <<"ID: "<<stud.ID<<endl;
	os <<"Comment: "<<stud.comment;
	if(stud.numCourses >0){
		for(unsigned int i=0;i<stud.numCourses;i++){
			cout<<"Course #"<<i<<endl;
		os<<*stud.courses[i];
		}
	}
	else cout<<"No Courses \n"<<endl;
	return os ;
}
/*******************************************************************************************************************************************************
Function Name:		EditStudent()
Purpose:			the function is used to add courses to the student or edit the comment related to the student.
					the function takes a user input of type integer and performs tasks related to those which are 1 and 2
					.1 for edit comment and 2 for add student course 
In Parameters:		None
out parameters:		NONE
Version:			2
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
void Student::EditStudent(){

	cout<<"1. Edit comment"<<endl<<"2. Add a new course"<<endl;
			int num;	//advantage of c++ intialize variables where needed 
			cin>> num;
			switch(num){
			case 1:
				char comm[1000];
				cout<<"Please enter the new comment:";
				cin.ignore();
				cin.getline(comm,sizeof(comm));
				comment=Comment(comm);
				cout<<"\n \n Student Edited! \n"<<endl;
				break;
			case 2:
				AddCourse();			//lets add a course to this student
				cout<<"\n \n Student Edited! \n"<<endl;
				break;
			default:
				cout<<"Error please select a valid answer ";
				break;
			} 
}
/*******************************************************************************************************************************************************
Function Name:		AddCourse()
Purpose:			this function takes in name of the course fee of the course and type of assessment the course consists of and  adds it the student object
					allocating dynamic memory where needed.
In Parameters:		None
out parameters:		NONE
Version:			6
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
void Student::AddCourse(){
	
	cout<<"Please enter the name of the course:";
	char course_name[20];
	cin>>course_name;
	cout<<"Please enter the fee :";
	float fee;
	cin>>fee;
	cout<<"PLease enter the type of assessment (1=exam,2=PLA,3=Project):";
	int num;
	cin>> num;
	Assessment * ass_type;					//creating a pointer of type assessment to hold the assessment related to the course added by the user
	switch(num){
	case 1:
	cout<<"Please enter the mark(/100):";
	float mark;
	cin >>mark;
	ass_type = new ExamAssessment(mark);
		break;
	case 2:
		cout<<"pleae enter the grade:";
		char in_grade;
		cin>>in_grade;
		ass_type = new PLAAssessment(in_grade);
		break;
	case 3:
		char titles[1000];
		cout<<"Please enter the project Title: ";
			cin.ignore();
			cin.getline(titles,sizeof(titles));
			cout<<"please enter the project mark(/100): ";
			float num;
			cin>>num;
		ass_type = new ProjectAssessment(titles,num);
		break;
	default:
		cout<<"error !";
		break;
	}
	Course **temp ;				// double pointer of type Course to 

	if (numCourses > 0) {
		temp = new Course*[numCourses + 1];			// allocating memory for temp array to hold old as well as new course
		for (unsigned int i = 0; i < numCourses; ++i) {
			temp[i] = courses[i];				//copying old course to the temp array
		}
		delete[] courses;		// delete what ever course we had earlier 
		courses = temp;			 
	}
	else {
		courses = new Course*[1];					
	}
	courses[numCourses++]= new Course(course_name,fee,ass_type);		//increamenting the course number here and also assigning the course to original coureses pointer
}
/*******************************************************************************************************************************************************
Function Name:		~Student()
Purpose:			releases memory allocated to by the courses 
In Parameters:		None
out parameters:		NONE
Version:			1
Author:				Lovejot Singh	
********************************************************************************************************************************************************/
Student::~Student(){
	unsigned int j=0;
	if(numCourses >j){			// j is unsigned 0 
		for(unsigned int loop=0;loop < numCourses ;loop++){				//delete all the courses added to 
		delete courses[loop];
		}
		delete[]courses;				// delete the course array 
	}
}
/******************************************************************************************************************************************************
*******************************************************************END OF FILE**************************************************************************/
