// The purpose of this program is to add and subtract complex numbers and print them in (a+bi) format
// this program does this without any errors
// this is the main program which interfaces with the program

#include "Complex.h"
#include <iostream>
#include <string>
using namespace std;

Complex obj;
double a1, a2, b1, b2;

void enterNum() //function to set the variables that will be sent to class
{
	cout << "Enter the real part of the first number: ";
	cin >> a1;
	while (cin.fail()) //will not continue until user inputs a number
	{
		cin.clear();
		cin.ignore();
		cout << "Please enter a number: ";
		cin >> a1;
	}
	cout << "Enter the imaginary part of the first number: ";
	cin >> b1;
	while (cin.fail()) //will not continue until user inputs a number
	{
		cin.clear();
		cin.ignore();
		cout << "Please enter a number: ";
		cin >> b1;
	}
	cout << "Enter the real part of the second number: ";
	cin >> a2;
	while (cin.fail()) //will not continue until user inputs a number
	{
		cin.clear();
		cin.ignore();
		cout << "Please enter a number: ";
		cin >> a2;
	}
	cout << "Enter the imaginary part of the second number: ";
	cin >> b2;
	while (cin.fail()) //will not continue until user inputs a number
	{
		cin.clear();
		cin.ignore();
		cout << "Please enter a number: ";
		cin >> b2;
	}
}

void plusComp() //sends numbers to class for addition
{
	enterNum();
	obj.addAB(a1, b1, a2, b2);
}

void minusComp() //sends numbers to class for subtraction
{
	enterNum();
	obj.subtractAB(a1, b1, a2, b2);
}


int main()
{
	char choice;
	bool done = false;
	cout << "This program is capable of adding or subtracting complex numbers.";
	while (true) //this program will loop until the user decides to exit
	{
		cout << "\nType in '+' to add, '-' to subtract, or '0' to exit: ";
		cin >> choice;
		do { // the switch will loop until the user chooses a valid choice or exits
			switch (choice)
			{
			case '+':
			{
				plusComp();
				done = true; //allows exit from loop
			}
			break;
			case '-':
			{
				minusComp();
				done = true;
			}
			break;
			case '0':
				return 0;
				break;
			default:
			{
				cout << "Please enter a valid choice: ";
				cin >> choice;
			}
			}
		} while (!done);
		done = false;
		cout << obj.printAB() << endl; // prints the answer from the class
	}

}