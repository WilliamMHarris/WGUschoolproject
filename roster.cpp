#include <iostream>
#include "roster.h"

using namespace std;

void Roster::siftInfo(string row) {
	int terminatingIndex = row.find(',');
	string id = row.substr(0, terminatingIndex);

	int startingIndex = terminatingIndex + 1;
	terminatingIndex = row.find(',', startingIndex);
	string firstN = row.substr(startingIndex, terminatingIndex - startingIndex);

	startingIndex = terminatingIndex + 1;
	terminatingIndex = row.find(',', startingIndex);
	string lastN = row.substr(startingIndex, terminatingIndex - startingIndex);

	startingIndex = terminatingIndex + 1;
	terminatingIndex = row.find(',', startingIndex);
	string eMail = row.substr(startingIndex, terminatingIndex - startingIndex);

	startingIndex = terminatingIndex + 1;
	terminatingIndex = row.find(',', startingIndex);
	int stuAge = stoi(row.substr(startingIndex, terminatingIndex - startingIndex)); //FIXME stoi() ~ DONE FIXING ON 10/17/20 AT 10:50AM
	                                                                                 // https:/^/www.bitdegree.org/learn/string-to-int-c-plus-plus
	startingIndex = terminatingIndex + 1;
	terminatingIndex = row.find(',', startingIndex);
	int daysComp1 = stoi(row.substr(startingIndex, terminatingIndex - startingIndex));

	startingIndex = terminatingIndex + 1;
	terminatingIndex = row.find(',', startingIndex);
	int daysComp2 = stoi(row.substr(startingIndex, terminatingIndex - startingIndex));

	startingIndex = terminatingIndex + 1;
	terminatingIndex = row.find(',', startingIndex);
	int daysComp3 = stoi(row.substr(startingIndex, terminatingIndex - startingIndex));

	startingIndex = terminatingIndex + 1;
	terminatingIndex = (row.size() - 1);
	string tempEnu = row.substr(startingIndex, terminatingIndex - startingIndex + 1);
	DegreeProgram deg = DATA_MANAGEMENT_DATA_ANALYTICS;
	if (tempEnu == "SECURITY") { deg = SECURITY; }
	else if (tempEnu == "NETWORK") { deg = NETWORK; }
	else if (tempEnu == "SOFTWARE") { deg = SOFTWARE; }
	else if (tempEnu == "DATA_MANAGEMENT_DATA_ANALYTICS") { deg = DATA_MANAGEMENT_DATA_ANALYTICS; }
	else { deg = UNDECLARED; } 

	createStudentObject(id, firstN, lastN, eMail, stuAge, daysComp1, daysComp2, daysComp3, deg);
}

void Roster::createStudentObject(string id, string firstN, string lastN, string eMail, int stuAge, int daysComp1, int daysComp2, int daysComp3, DegreeProgram deg) {
	int dArray[3] = { daysComp1, daysComp2, daysComp3 };
	classRosterArray[++iterationNum] = new Student(id, firstN, lastN, eMail, stuAge, dArray, deg);
}

void Roster::removeStudentByID(string id) {
	for (int j = 0; j <= iterationNum; ++j) {
		if (id == classRosterArray[j]->getStudentID()) {
			cout << "Removing student associated with " << id << endl;
		}
		else if ((id != classRosterArray[j]->getStudentID()) && (classRosterArray[j]->getStudentID())=="Empty") {cout <<
			"Error: Student with " << id << " is not found!" << endl << endl; } 
	}
	for (int i = 0; i <= Roster::iterationNum; ++i) {
		if ((classRosterArray[i]->getStudentID()) == id) {
			id = "Empty";
			string firstN = "  ";
			string lastN = "  ";
			string eMail = "NA@school.edu";
			int stuAge = 0;
			int daysComp[] = { 0, 0, 0 };
			DegreeProgram deg = UNDECLARED;
			classRosterArray[i]->setStudentID(id);
			classRosterArray[i]->setFirstName(firstN);
			classRosterArray[i]->setLastName(lastN);
			classRosterArray[i]->setStudentEmail(eMail);
			classRosterArray[i]->setStudentAge(stuAge);
			classRosterArray[i]->setdaysToComplete(daysComp); 
			classRosterArray[i]->setDegreeProgram(deg);
		}
		else { cout << ""; }
		}
	}

void Roster::printAll() {
	cout << endl << "ID  |      First Name       |      Last Name        |     Age      |      Days To Complete         |           Degree"  << endl << endl;
	for (int i = 0; i <= Roster::iterationNum; ++i) {
		cout << classRosterArray[i]->getStudentID(); cout << '\t';
		cout << "First Name: " << classRosterArray[i]->getStudentFirstName(); cout << '\t';
		cout << "Last Name: " << classRosterArray[i]->getStudentLastName(); cout << '\t';
		/*cout << classRosterArray[i]->getStudenteMail(); cout << '\t'; // the instructions E.3.c skips email*/
		cout << "Age: " << classRosterArray[i]->getStudentage(); cout << '\t' << '\t';
		cout << "daysInCourse: {";
		cout << classRosterArray[i]->getdaysToComplete()[0]; cout << " ";
		cout << classRosterArray[i]->getdaysToComplete()[1]; cout << ' ';
		cout << classRosterArray[i]->getdaysToComplete()[2]; cout << "}" << '\t';
		cout << "Degree Program: ";
		if ((classRosterArray[i]->getDegreeProgram()) == 0) {cout << "SECURITY ";}
		else if ((classRosterArray[i]->getDegreeProgram()) == 1) { cout << "NETWORK"; }
		else if ((classRosterArray[i]->getDegreeProgram()) == 2) { cout << "SOFTWARE"; }
		else if ((classRosterArray[i]->getDegreeProgram()) == 3) { cout << "DATA_MANAGEMENT_DATA_ANALYTICS"; }
		else { cout << "UNDECLARED"; }
		cout << endl;
	}
	cout << endl;
	cout << endl;
}

void Roster::printAverageDaysInCourse(string id) {
	cout << "Average Days In Course:" << endl << endl;
	for (int i = 0; i <= Roster::iterationNum; ++i) {
		cout << classRosterArray[i]->getStudentID() << " " << classRosterArray[i]->getStudentFirstName() << " " << classRosterArray[i]->getStudentLastName() <<
			": " << ((classRosterArray[i]->getdaysToComplete()[0] + classRosterArray[i]->getdaysToComplete()[1] +
				classRosterArray[i]->getdaysToComplete()[2]) / 3.0) << " Average of days in course" << endl;
	}
}

void Roster::printInvalidEmails() {
	cout << "Printing Invalid E-mails" << endl << endl;
	for (int i = 0; i <= Roster::iterationNum; ++i) {
		int j = 0;
		int k = 0;
		int l = 0;
		int m = 0;
		bool statusc = true;
		string tempeMail = classRosterArray[i]->getStudenteMail(); 
		int sos = tempeMail.size();
		for (int n = 0; n < sos; ++n) {
			if (tempeMail.at(n) == '@') {  j += 1; l = n; }
			if (tempeMail.at(n) == '.') {  k += 1; m = tempeMail.find('.', l); }
			if (tempeMail.at(n) == ' ') { statusc = false; }
		}
		if ((j > 0) && (k > 0) && (statusc == true) && (m > l)) { cout << " "; }
		else { cout << tempeMail << " is an invalid E-mail address and is associated with student ID#: " << classRosterArray[i]->getStudentID() << endl; }
		}
	cout << endl << "  " << endl << endl;
	}

void Roster::printByDegreeProgram(DegreeProgram deg) { 
	cout << "                        STUDENTS BY DEGREE PROGRAM" << endl;
	cout << "ID| First Name| Last Name|      e-Mail         | Age | Days To Complete | Degree" << endl << endl;
	for (int i = 0; i <= iterationNum; ++i) {
		if (classRosterArray[i]->getDegreeProgram() == deg) {
			cout << classRosterArray[i]->getStudentID() << '\t';
			cout << classRosterArray[i]->getStudentFirstName() << '\t';
			cout << classRosterArray[i]->getStudentLastName() << '\t' << "  ";
			cout << classRosterArray[i]->getStudenteMail() << '\t' << "  ";
			cout << classRosterArray[i]->getStudentage() << '\t' << '{';
			cout << classRosterArray[i]->getdaysToComplete()[0] << ", ";
			cout << classRosterArray[i]->getdaysToComplete()[1] << ", ";
			cout << classRosterArray[i]->getdaysToComplete()[2] << "} " << '\t';
			if ((classRosterArray[i]->getDegreeProgram()) == 0) { cout << "SECURITY "; }
			else if ((classRosterArray[i]->getDegreeProgram()) == 1) { cout << "NETWORK"; }
			else if ((classRosterArray[i]->getDegreeProgram()) == 2) { cout << "SOFTWARE"; }
			else if ((classRosterArray[i]->getDegreeProgram()) == 3) { cout << "DATA_MANAGEMENT_DATA_ANALYTICS"; }
			else { cout << "UNDECLARED"; }
			cout << endl;
		}
	}
	cout << endl << endl;
}

void Roster::printByFirstName(string firstN) { 
	cout << "Printing Student with a specific First Name: " << firstN << endl;
	cout << "ID  | First & Last Name|      e-Mail         | Age | Days To Complete | Degree" << endl << endl;
	for (int i = 0; i <= iterationNum; ++i) {
		if (classRosterArray[i]->getStudentFirstName() == firstN) {
			classRosterArray[i]->printStudentInfo();
		}
	}
	cout << endl << endl << endl;
}

	Roster::~Roster() {
	cout << "Destroying Student Objects" << endl << endl;
	for (int i = 0; i < numStudents; ++i) {
		cout << "Erasing ";
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
	cout << "Success";
}
