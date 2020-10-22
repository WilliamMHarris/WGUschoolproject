#pragma once
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

class Student {
    public:
		Student();
		Student(string id, string firstN, string lastN, string eMail, int stuAge, int dArray[], DegreeProgram deg);
		// the following are the accessor member functions. 
	   string getStudentID();
	   string getStudentFirstName();
	   string getStudentLastName();
	   string getStudenteMail();
	   int getStudentage();
	   int* getdaysToComplete();
	  DegreeProgram getDegreeProgram();

	  // the next line is the specific student print function.
	  void printStudentInfo();

	  // the following are the mutator member functions. 
	  void setStudentID(string id);
	  void setFirstName(string firstN);
	  void setLastName(string lastN);
	  void setStudentEmail(string eMail);
	  void setStudentAge(int stuAge);
	  void setdaysToComplete(int daysComp[]);
	  void setDegreeProgram(DegreeProgram deg);


    private:
		string studentID; 
		string firstName;
		string lastName;
		string studenteMail;
		int age;
		int daysToComplete[3];
		DegreeProgram degreeProgram;

};

