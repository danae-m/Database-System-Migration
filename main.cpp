#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {
	cout << "C867 - Scripting & Programming Applications" << endl ;
	cout << "Language: C++  -  Student ID: 010270658  -  B. Danae Miller" << endl << endl ;
	
	int i ;
	Roster classRoster ;
		
	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
								   "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
								   "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
								   "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
								   "A5,Danae,Miller,bmil730@wgu.edu,31,25,45,63,SOFTWARE" 
	} ;

	for (i = 0; i < 5; ++i) {
		classRoster.Parse(studentData[i]) ;
	}
	
	classRoster.PrintAll();
	cout << endl ;

	classRoster.PrintBadEmails();
	cout << endl ;
	
	classRoster.PrintAvgDays() ;
	cout << endl ;
	
	classRoster.PrintByDP(SOFTWARE);
	cout << endl ;

	classRoster.Remove("A3");
	cout << endl ;

	classRoster.PrintAll();
	cout << endl ;

	classRoster.Remove("A3");
	cout << endl ;

	return 0; 
}