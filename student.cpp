#include <iostream>
#include <string>
#include <vector>
#include "degree.h"
#include "student.h"

using namespace std;

Student::Student(){
	studentID = "None";
	firstName = "None";
	lastName = "None";
	studenteMail = "NA@nothing.com";
	age = 0;
	daysToComplete[3] = { 0 }; 
	degreeProgram = UNDECLARED;
}

Student::Student(string id, string firstN, string lastN, string eMail, int stuAge, int dArray[], DegreeProgram deg) {
	studentID = id;
	firstName = firstN;
	lastName = lastN;
	studenteMail = eMail;
	age = stuAge;
	for (int i = 0; i < 3; ++i) {
		daysToComplete[i] = dArray[i];
	}
	degreeProgram = deg;
}

string Student::getStudentID() { return studentID; }
string Student::getStudentFirstName() { return firstName; }
string Student::getStudentLastName() { return lastName; }
string Student::getStudenteMail() {return studenteMail; }
int Student::getStudentage() { return age; }
int* Student::getdaysToComplete() { return daysToComplete; }
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

void Student::printStudentInfo() {
	cout << this->getStudentID() << '\t';
	cout << this->getStudentFirstName() << " " << this->getStudentLastName() << '\t';
	cout << this->getStudenteMail() << '\t';
	cout << this->getStudentage() << '\t';
	for (int i = 0; i < 3; ++i) {
		cout << getdaysToComplete()[i] << ','; 
	}
	cout << '\t';  
	if (getDegreeProgram() == 0) { cout << "SECURITY"; }
	if (getDegreeProgram() == 1) { cout << "NETWORK"; }
	if (getDegreeProgram() == 2) { cout << "SOFTWARE"; }
	if (getDegreeProgram() == 3) { cout << "DATA_MANAGEMENT_DATA_ANALYTICS"; }
	if (getDegreeProgram() > 3) { cout << "UNDECLARED"; }
}

void Student::setStudentID(string id) { studentID = id; }
void Student::setFirstName(string firstN) { firstName = firstN; }
void Student::setLastName(string lastN) { lastName = lastN; }
void Student::setStudentEmail(string eMail) { studenteMail = eMail; }
void Student::setStudentAge(int stuAge) { age = stuAge; }
void Student::setdaysToComplete(int daysComp[]) { for (int i = 0; i < 3; ++i) daysToComplete[i] = daysComp[i]; }
void Student::setDegreeProgram(DegreeProgram deg) { degreeProgram = deg; }

