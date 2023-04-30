#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

void Roster::Add(string userStudentID,string userFirstName,string userLastName,string userEmail,
				 int userAge,int userDays1,int userDays2,int userDays3,string userDegreeProgram) {
	Student* S = new Student(userStudentID,userFirstName,userLastName,userEmail,
							 userAge,userDays1,userDays2,userDays3,userDegreeProgram) ;
	classRosterArray[index] = S ;
	++index ;
}

void Roster::Remove(string studentID) {
	for(i = 0 ; i < 5 ; ++i) {
		if(!(classRosterArray[i] == nullptr)) {
			if(classRosterArray[i]->GetStudentID() == studentID) {
				delete classRosterArray[i] ;
				classRosterArray[i] = nullptr ;
				cout << "Removing student with ID " << studentID << "." << endl ;
			}
		}
		else {
			cout << "No student with ID " << studentID << " found." << endl ;
		}
	}
}

void Roster::PrintAll() {
	cout << "Printing Roster: " << endl ;
	for(i = 0 ; i < 5 ; ++i) {
		if(classRosterArray[i] == nullptr) {
		}
		else {
			classRosterArray[i]->Print() ;
		}
	}
}

void Roster::PrintAvgDays() {
	cout << "Displaying Average Course Completion Time: " << endl ;
	for(i = 0 ; i < 5 ; ++i) {
		if(!(classRosterArray[i] == nullptr)) {
			num1 = classRosterArray[i]->GetNumDays1() ;
			num2 = classRosterArray[i]->GetNumDays2() ;
			num3 = classRosterArray[i]->GetNumDays3() ;
			numAvg = (num1 + num2 + num3) / 3 ;
			cout << "Student ID: " << classRosterArray[i]->GetStudentID() << ", average days in course is: " << numAvg << endl ;
		}
	}
}

int Roster::FindAvgDays(string stID) {
	for(i = 0 ; i < 5 ; ++i) {
		if(!(classRosterArray[i] == nullptr)) {
			if(classRosterArray[i]->GetStudentID() == stID) {
				num1 = classRosterArray[i]->GetNumDays1() ;
				num2 = classRosterArray[i]->GetNumDays2() ;
				num3 = classRosterArray[i]->GetNumDays3() ;
			}
		}
		numAvg = (num1 + num2 + num3) / 3 ;
		return numAvg ;
	}
}

void Roster::PrintBadEmails() {
	cout << "Displaying Invalid Emails: " << endl ;
	for(i = 0 ; i < 5 ; ++i) {
		if(classRosterArray[i]->GetEmail().find('@') == string::npos || 
		   classRosterArray[i]->GetEmail().find('.') == string::npos || 
		   classRosterArray[i]->GetEmail().find(' ') != string::npos) {
			cout << classRosterArray[i]->GetEmail() << " is invalid." << endl ;
		}
	}
}

void Roster::PrintByDP(DegreeProgram degreeProgram) {
	if(degreeProgram == DegreeProgram::SOFTWARE) {
		degreeString = "Software" ;
	}
	else if(degreeProgram == DegreeProgram::SECURITY) {
		degreeString = "Security" ;
	}
	else if(degreeProgram == DegreeProgram::NETWORK) {
		degreeString = "Network" ;
	}
	cout << "Printing All Students of Degree Type: " << degreeString << endl ;
	for(i = 0 ; i < 5 ; ++i) {
		if(!(classRosterArray[i] == nullptr)) {
			if(classRosterArray[i]->GetDegreeProgram() == degreeString) {
				classRosterArray[i] -> Print() ;
			}
		}
	}
}

void Roster::Parse(string userData) {
	size_t rhs = userData.find(",") ;
	string userStudentID = userData.substr(0,rhs) ;

	size_t lhs = rhs + 1 ;
	rhs = userData.find(",",lhs) ;
	string userFirstName = userData.substr(lhs,rhs - lhs) ;

	lhs = rhs + 1 ;
	rhs = userData.find(",",lhs) ;
	string userLastName = userData.substr(lhs,rhs - lhs) ;

	lhs = rhs + 1 ;
	rhs = userData.find(",",lhs) ;
	string userEmail = userData.substr(lhs,rhs - lhs) ;

	lhs = rhs + 1 ;
	rhs = userData.find(",",lhs) ;
	int userAge = stoi(userData.substr(lhs,rhs - lhs)) ;

	lhs = rhs + 1 ;
	rhs = userData.find(",",lhs) ;
	int userDays1 = stoi(userData.substr(lhs,rhs - lhs)) ;

	lhs = rhs + 1 ;
	rhs = userData.find(",",lhs) ;
	int userDays2 = stoi(userData.substr(lhs,rhs - lhs)) ;

	lhs = rhs + 1 ;
	rhs = userData.find(",",lhs) ;
	int userDays3 = stoi(userData.substr(lhs,rhs - lhs)) ;

	lhs = rhs + 1 ;
	rhs = userData.find(",",lhs) ;
	string userDegreeProgram = userData.substr(lhs,rhs - lhs) ;

	Add(userStudentID,userFirstName,userLastName,userEmail,userAge,userDays1,userDays2,userDays3,userDegreeProgram) ;
}

Roster::~Roster() {
	cout << "Calling Destructor..." << endl ;
	for(i = 0 ; i < 5 ; ++i) {
		if(!(classRosterArray[i] == nullptr)) {
			delete classRosterArray[i] ;
			classRosterArray[i] = nullptr ;
		}
	}
	cout << "Destruction Completed." << endl ;
}