#pragma once
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

class Student {
public:
	void SetStudentID(string userStudentID) ;
	void SetFirstName(string userFirstName) ;
	void SetLastName(string userLastName) ;
	void SetEmail(string userEmail) ;
	void SetAge(int userAge) ;
	void SetNumDays (int days1, int days2, int days3) ;
	void SetDegreeProgram(string userDegreeProgram) ;

	string GetStudentID() ;
	string GetFirstName() ;
	string GetLastName() ;
	string GetEmail() ;
	int GetAge() ;
	int GetNumDays1() ;
	int GetNumDays2() ;
	int GetNumDays3() ;
	string GetDegreeProgram() ;

	Student() ;
	Student(string userStudentID, string userFirstName, string userLastName, string userEmail, int userAge, int userDays1, int userDays2, int userDays3, string userDegreeProgram) ;

	void Print() ;


private:
	string studentID ;
	string firstName ;
	string lastName ;
	string email ;
	int age ;
	int days1, days2, days3 ;
	int numDays[3] ;
	string degreeString ;
	DegreeProgram degreeProgram ;

} ;