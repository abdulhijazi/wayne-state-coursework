// This main program allows the user to view and edit employee data
// This program operates as expected and does not allow the input of invalid selections at any menus

#include <iostream>
#include <string>
#include <iomanip> //library used to tabulate employee data
#include "Employee.h"
using namespace std;


Employee emp1, emp2; //2 objects to be used with class Employee

void initializeEmp() //function to initialize employee values
{
	emp1.setFirst("Abdul");
	emp1.setLast("Hijazi");
	emp1.setSalary(15000);
	emp2.setFirst("John");
	emp2.setLast("Smith");
	emp2.setSalary(5000);
}

void tabulate() //function to tabulate employee data
{
	cout << setw(6) << "EMP#" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(10) << "$/Month" << setw(12) << "$/Year" << endl;
	cout << setw(6) << "1" << setw(15) << emp1.getFirst() << setw(15) << emp1.getLast() << setw(10) << emp1.getSalary() << setw(12) << emp1.getSalary() * 12 << endl;
	cout << setw(6) << "2" << setw(15) << emp2.getFirst() << setw(15) << emp2.getLast() << setw(10) << emp2.getSalary() << setw(12) << emp2.getSalary() * 12 << endl;

}

void changeEmp() //function to change employee values
{
	int empnum, s;
	string f, l;
	cout << "Enter the employee's number: ";
	cin >> empnum;
	while ((empnum < 1) || (empnum > 2) || cin.fail()) //This program only has employees 1 and 2, therefore it will not allow input of anything greater than 2 or less than 1 or any letters
	{
		cin.clear();
		cin.ignore();
		cout << "Please enter a valid employee number: ";
		cin >> empnum;
	}
	cout << "Enter the employee's new first name: "; //prompts user for new employee's information
	cin >> f;
	cout << "Enter the employee's new last name: ";
	cin >> l;
	cout << "Enter the employee's new monthly salary: ";
	cin >> s;
	while (cin.fail()) //will not continue until user inputs a number
	{
		cin.clear();
		cin.ignore();
		cout << "Please enter a number: ";
		cin >> s;
	}
	if (empnum == 1) //if user chose to change employee 1's data
	{
		emp1.setFirst(f);
		emp1.setLast(l);
		emp1.setSalary(s);
	}
	if (empnum == 2) //if user chose to change employee 2's data
	{
		emp2.setFirst(f);
		emp2.setLast(l);
		emp2.setSalary(s);
	}
}

void raise() //function to give employees 10 percent raise
{
	int newsalary, currentsalary; //two variables to be used within function
	currentsalary = emp1.getSalary(); //gets employee's initial salary, multiplies by 0.1, then saves new salary
	newsalary = currentsalary * 11 / 10;
	emp1.setSalary(newsalary);
	currentsalary = emp2.getSalary(); //does this again for 2nd employee
	newsalary = currentsalary * 11 / 10;
	emp2.setSalary(newsalary);
}



int main()
{
	char choice; //variable for choice in selection menus
	bool done = false; //for checking of completion inside

	initializeEmp(); //calls to initialize employees

	cout << "Below are the company's employees:\n\n"; //tabulates employee data using iomanip and retrieves employee data from class
	tabulate(); //calls function to tabulate employee data
	cout << "\nWould you like to re-enter an employee's information? (Y/N) "; //prompts user if they would like to re-enter an employee's data
	cin >> choice;
	do { //the switch will loop until the boolean done is set to true
		switch (choice)
		{
		case 'Y': case 'y': //if the user enters Y for yes, it will call the function to change employee data
		{
			while ((choice == 'Y') || (choice == 'y'))
			{
				changeEmp();
				cout << "Would you like to make any other modifications? (Y/N) "; //asks if user would like to make any other changes
				cin >> choice; //after this, the switch loops again and will check if the user entered Y again
			}
		} break;
		case 'N': case 'n': //if user enters N for no, the boolean done will be set to true and the program continues
		{done = true; }
		break;
		default: //this occurs when the user enters an invalid choice and the user will be prompted to input something else
		{
			cout << "Please enter a valid choice of Y or N: ";
			cin >> choice;
		}

		}
	} while (!done); //will loop until done is true. in reality, this loop will not exit until the user enters No at least once
	done = false; //resets boolean done to false for use with next switch
	cout << "Would you like to give the employees a 10% raise? (Y/N) "; // prompts user if they would like to add 10 percent to salaries
	cin >> choice;
	do {
		switch (choice) // uses same choice variable
		{
		case 'Y': case 'y': //if user chooses yes, the function to add 10 percent is called then the switch is exited
		{
			raise();
			done = true;
		} break;
		case 'N': case 'n': //if user chooses not to add 10 percent, boolean done is set to true and the switch exits
		{done = true; }
		break;
		default: //if the user chooses an invalid choice, the program will prompt the user to try again and loop the switch
		{
			cout << "Please enter a valid choice of Y or N: ";
			cin >> choice;
		}

		}
	} while (!done);

	cout << "Below is the updated employee data:\n\n";
	tabulate(); //calls function to tabulate employee data again
	cout << "\nPress Enter to exit the program...\n";
	cin.ignore(); //this is done so program waits until enter to close the program so user can see last outputted data
	cin.get();
	return 0;
}