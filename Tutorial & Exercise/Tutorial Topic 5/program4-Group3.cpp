#include<iostream>
#include<string>
#include<cmath>
#include <algorithm>

using namespace std;

// Task 1: Define the function lowercase that converts a string to lower case
string lowercase(string s)
{
 for (int i = 0; i < s.length(); i++)
  	{
  		s[i] = tolower(s[i]);
  	}

    return s;
}

string removeSpaces(string str){
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

// Task 2: Define the function textToNumber that converts a number in word to its integer value
int textToNumber(string txt)
{
	if(txt == "zero") return 0;
	if(txt == "one") return 1;
	if(txt == "two") return 2;
	if(txt == "three") return 3;
	if(txt == "four") return 4;
	if(txt == "five") return 5;

}

string numberToText(int n, string &str)
{
	if(n==0) str = "zero";
	if(n==1) str = "one";
	if(n==2) str = "two";
	if(n==3) str = "three";
	if(n==4) str = "four";
	if(n==5) str = "five";
	if(n==6) str = "six";
	if(n==7) str = "seven";
	if(n==8) str = "eight";
	if(n==9) str = "nine";
	if(n==10) str = "ten";
}

int main()
{
	int value1, value2;
	bool negativeVal = false;
	// Task 3a: Read user input
	string text;
	cout <<"What is: ";
	getline(cin, text);
	
	// Task 3b: Convert the user input to lower case
	text = lowercase(text);
	
	// Task 4: Extract words of the first and second operands as well as the operator
	size_t pos1, pos2, pos3;
	string operand1, operatorVar, operand2;

	pos1 = text.find(' ');				//operand 1 
	pos2 = text.find(' ',pos1);			//operator
	pos3 = text.length() - pos1 - pos2;	//operand 2

	operand1 = text.substr(0,pos1);
	operatorVar = text.substr(pos1+1, pos2+1);
	operand2 = text.substr(pos1+pos2+2, pos3);

    operand1 = removeSpaces(operand1);
    operatorVar = removeSpaces(operatorVar);
    operand2 = removeSpaces(operand2);

	// Task 5: Convert the operands from words to integers
	value1 = textToNumber(operand1);
	value2 = textToNumber(operand2);
	
	// Task 6: Perform the arithmetic calculation accordingly, i.e., addition or subtraction
	int result;
	if(operatorVar == "plus") result = value1 + value2;
	if(operatorVar == "minus") result = value1 - value2;
	
	// Task 7: Convert the result from integer to word

	if(result<0){
		result = -result;
		negativeVal = true;
	} 

	string sResult;
	numberToText(result, sResult);
	
	// Task 8: Print the answer
	if(negativeVal == true){
	cout << "Answer: " << operand1 << " " << operatorVar << " "<<  operand2 << " is negative " << sResult;
	}else{
	cout << "Answer: " << operand1 << " " << operatorVar << " "<<  operand2 << " is " << sResult;
	}

	cout << endl << endl;

	system("pause"); //! remove this line if you are using Dev C++
	return 0;
}
