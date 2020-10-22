#pragma once
#include <iostream>
#include "student.h"


using namespace std;

class Roster {
public:
	
	void siftInfo(string row);
	void createStudentObject(string id, string firstN, string lastN, string eMail, int stuAge, int daysComp1, int daysComp2, int daysComp3, DegreeProgram deg);
	void removeStudentByID(string id);
	void printAll();
	void printAverageDaysInCourse(string id);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram deg);
	void printByFirstName(string firstN);   
	~Roster();

private:
	int iterationNum = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];
};

