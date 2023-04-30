#pragma once
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

class Roster {
	public:
		void Add(string userStudentID,string userFirstName,string userLastName,string userEmail,
				 int userAge,int userDays1,int userDays2,int userDays3,string userDegreeProgram) ;

		void Remove(string studentID) ;

		void PrintAll() ;

		void PrintAvgDays() ;

		int FindAvgDays(string studentID) ;

		void PrintBadEmails() ;

		void PrintByDP(DegreeProgram degreeProgram) ;

		void Parse(string userData) ;

		~Roster() ;

	private:
		Student* classRosterArray[5] ;
		string degreeString ;
		string userData ;
		unsigned int i ;
		int num1, num2, num3, numAvg ;
		int index = 0;
};
