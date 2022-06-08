#include<iostream>
#include<string>
#include<cstring>
#include <algorithm>
using namespace std;

string removeSpaces(string str){
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

int main()
{
    string expression;
	string operand1, operand2, operation;
    double value1, value2, result;
    
    // Task 1: Read the string of arithmetic expression and put it into the variable "expression"
	cout <<"Enter an arithmetic expression, e.g. 20 + 30  => ";
	getline(cin, expression);
	
    
    // Task 2: Extract the operator and both operands from "expression" and 
	//           put them into the variables "operation", "operand1", and "operand2", accordingly
		
    size_t operand1Found, operand2Found, operationFound;
    operand1Found = expression.find(" ");
    operationFound = expression.find(" ", operand1Found);
    operand2Found = expression.length() - operand1Found - operationFound;
    
    operand1 = expression.substr(0,operand1Found);
    operation = expression.substr(operand1Found+1, operationFound);
    operand2 = expression.substr(operationFound+operand1Found, operand2Found);

    operand1 = removeSpaces(operand1);
    operand2 = removeSpaces(operand2);
    operation = removeSpaces(operation);
    
	// Task 3:  Convert the string operands to numbers. 
	//            Put the numbers into variables "value1" and "value2", respectively
	
	value1 = stod(operand1);
    value2 = stod(operand2);
    
    // Task 4: Determine the type of operation (i.e., either +, -, *, or / ) and perform the arithmetic calculation accordingly.
    //          Put the result of the calculation into the variable "result".
    
    if(operation == "+") result = value1 + value2;
    if(operation == "-") result = value1 - value2;
    if(operation == "*") result = value1 * value2;
    if(operation == "/") result = value1 / value2;
	
	
    cout << "The value of the expression " << expression << " is " << result << endl << endl;
    
    system("pause"); //! remove this line if you are using Dev C++
    return 0;
}

