#include <iostream>
#include <string>
#include "student.h"
using namespace std;

void Student::SetStudentID(string userID) {
	studentID = userID ;
}
void Student::SetFirstName(string userFirstName) {
	firstName = userFirstName ;
}
void Student::SetLastName(string userLastName) {
	lastName = userLastName ;
}
void Student::SetEmail(string userEmail) {
	email = userEmail ;
}
void Student::SetAge(int userAge) {
	age = userAge ;
}
void Student::SetNumDays(int userDays1, int userDays2, int userDays3) {
	numDays[0] = userDays1 ;
	numDays[1] = userDays2 ;
	numDays[2] = userDays3 ;
	days1 = userDays1 ;
	days2 = userDays2 ;
	days3 = userDays3 ;
}
void Student::SetDegreeProgram(string userDegreeProgram) {
	if(userDegreeProgram == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY ;
	}
	else if(userDegreeProgram == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK ;
	}
	else if(userDegreeProgram == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE ;
	}
}

string Student::GetStudentID() {
	return studentID ;
}
string Student::GetFirstName() {
	return firstName ;
}
string Student::GetLastName() {
	return lastName ;
}
string Student::GetEmail() {
	return email ;
}
int Student::GetAge() {
	return age ;
}
int Student::GetNumDays1() {
	return days1 ;
}
int Student::GetNumDays2() {
	return days2 ;
}
int Student::GetNumDays3() {
	return days3 ;
}
string Student::GetDegreeProgram() {
	if(degreeProgram == DegreeProgram::SOFTWARE) {
		degreeString = "Software" ;
	}
	if(degreeProgram == DegreeProgram::SECURITY) {
		degreeString = "Security" ;
	}
	if(degreeProgram == DegreeProgram::NETWORK) {
		degreeString = "Network" ;
	}
	return degreeString ;
}

Student::Student() {
	studentID = -1 ;
	firstName = "unknown" ;
	lastName = "unknown" ;
	email = "unknown" ;
	age = -1 ;
	numDays[0] = -1 ;
	numDays[1] = -1 ;
	numDays[2] = -1 ;
}
Student::Student(string userStudentID, string userFirstName, string userLastName, string userEmail, int userAge, int userDays1, int userDays2, int userDays3, string userDegreeProgram) {
	SetStudentID(userStudentID) ;
	SetFirstName(userFirstName) ;
	SetLastName(userLastName) ;
	SetEmail(userEmail) ;
	SetAge(userAge) ;
	SetNumDays(userDays1, userDays2, userDays3) ;
	SetDegreeProgram(userDegreeProgram) ;
}

void Student::Print() {
	cout << GetStudentID() << '\t' << "First Name: " << GetFirstName() << '\t' << "Last Name: " << GetLastName() << '\t'
		 << "Age: " << GetAge() << '\t' << "daysInCourse: {" << GetNumDays1() << "," << GetNumDays2() << "," << GetNumDays3() << "}"
		 << '\t' << "Degree Program: " << GetDegreeProgram() << ". " << endl;
}