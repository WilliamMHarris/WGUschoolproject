#pragma once
#include <iostream>
#include "degree.h"
#include <string>
#include "student.h"
#include "roster.h"
#include <cctype>

using namespace std;


int main() {

	cout << "Course: Scripting and Programming Applications" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "Student ID: 001295033" << endl;
	cout << "Student Name: William Harris" << endl << endl;

	const string studentData[] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,William,Harris,wharr79@my.wgu.edu,31,20,30,35,DATA_MANAGEMENT_DATA_ANALYTICS"
	};

	const int numStudents = 5;
	Roster roster;

	Roster classRoster;

	for (int i = 0; i < numStudents; ++i) {
		classRoster.siftInfo(studentData[i]);
	}

	classRoster.printAll();        //FIXME!!!!!! - fixed on 10/20/20 8:02pm

	classRoster.printInvalidEmails();

	classRoster.printByFirstName("William");

	classRoster.printAverageDaysInCourse(studentData[0]);

	cout << endl << endl << endl << endl;

	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.removeStudentByID("A3");
	classRoster.printAll();
    classRoster.removeStudentByID("A3");
	

	return 0;
}