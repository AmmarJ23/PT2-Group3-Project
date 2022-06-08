#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <conio.h>
#include <sstream>
using namespace std;

int main()
{
	char name[100];
	string id;
	string idTemp;
	
	// Task 1: Allow user to enter his or her full name and id number
	cout << "Enter your full name => ";
	//getline(cin,name);
	cin.getline(name, 100);

	cout << "Enter your ID Number => ";
	getline(cin,id);


	// Task 2: To determine the gender from the last digit
	// Task 2a: Extract the last digit from the id
	idTemp = id;
	idTemp = idTemp.substr(12,1);

	// Task 2b: Convert the last digit to a number
	//________________________
	int lastDigit = 0;
	stringstream convToInt(idTemp);
	convToInt << lastDigit;
	
	// Task 2c: Determine the gender such that, an odd value is male and even is female
	string gender;
	if (lastDigit % 2 == 0){
		//lastDigit = even
		gender = "Female";
	}else {
		//lastDigit = odd
		gender = "Male";
	}
	
	// Task 3: To extract the dob
	// Task 3a: Extract the year, month and day from the id
	string sYear  = id.substr(0,2);
	string sMonth = id.substr(2,2);
	string sDay = id.substr(4,2);

	int Year, Month, Day;
	string MONTHS[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

	// Task 3b: convert the year, month and day to integers
	Year = stoi(sYear);
	Month = stoi(sMonth);
	Day = stoi(sDay);

	// Task 3c: Convert the year to be in full value form, e.g. 99 becomes 1999 and 02 becomes 2002
	if (Year>18 && Year<100){
		Year = 1900 + Year;
	} else{
		Year = 2000 + Year;
	}
	
	// Task 4: Calculate the age
	//________________________
	int Age;
		Age = 2018 - Year;
	
	// Task 5: Determine the string name for the month
	//________________________
	Month--;
	sMonth = MONTHS[Month];

	// Task 6: Using a loop, convert the name to capital letters
	for(int i=0; i<strlen(name);i++){
		name[i] = toupper(name[i]);
	}

	// Task 7: print all the required output
	cout << "Output: " << endl << endl;
	cout << "Name    : " << name << endl;
	cout << "ID      : " << id << endl;
	cout << "Gender  : " << gender << endl;
	cout << "Age     : " << Age << " years old" << endl;
	cout << "DOB     : " << sDay << " " << sMonth << " " << Year << endl << endl;

	cout << "\n\nPress any key to exit the program..." << endl;
    getch();

    return 0;
	
}