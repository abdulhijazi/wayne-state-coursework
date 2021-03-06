// This program can find the find (a) the factorial of a nonnegative integer
// (b) estimate the value of e (with desired accuracy of summation terms depending on user input)
// (c) compute e^x (with desired accuracy of terms depending on user input)
// the program does these operations correctly and were verified with a calculator

#include <iostream>
using namespace std;

int factorial(int input) //function to calculate the factorial
{
	int x = 1; //counter for number of times operation is done
	int y = 1; //answer
	while (x <= input) //does operation until counter is equal to user input 
	{
		y *= x; // result will now equal initial number times counter
		x++; // counter incremented
	}
	return y; //returns the result
}

double accE(int input) //function to estimate e to a certain accuracy
{
	int x = 1; //counter
	double y = 1; //result is double because answer may be decimal
	while (x <= input) //will do operation until counter equals input
	{
		y += 1.0 / factorial(x); //calls upon first function
		x++;
	}
	return y; //returns the result
}

double etox(int input, double inputx) // function to estimate e to the power x
{
	int x = 1; //counter
	double y = 1.0; //result is double because may include decimal
	double pow = inputx; //user input may also be decimal value
	while (x <= input)
	{
		y += pow / factorial(x); // calls upon first function
		pow *= inputx;
		x++;
	}
	return y;
}

int main()
{
	int input; //used for integer user input
	char function; //choice of operation
	double inputx; //used for decimal user input
	cout << "This program is capable of doing the following:\n(a) Finding the factorial of a nonnegative number\n(b) Estimating the value of the mathematical constant e to a desired accuracy\n(c) Estimating the value of e^x to a desired accuracy\n You may enter 0 to exit the program.\n";
	while (true) //program will continue to loop until user inputs 0 at selection screen
	{
		cout << "\nPlease input the letter of the desired operation to perform: ";
		cin >> function;
		switch (function) //enters switch based on user input at function selection menu
		{
		case 'A': case 'a': //case A which calls upon factortial function
		{
			cout << "Please enter the factorial base: ";
			cin >> input;
			while ((input < 0) || cin.fail()) //checks if number is integer and nonnegative
			{
				cin.clear();
				cin.ignore();
				cout << "Please enter a number that is nonnegative: ";
				cin >> input;
			}
			cout << input << "!=" << factorial(input) << endl;

		}break;
		case 'B': case 'b': //choice B which calls upon function that finds e to a certain accuracy
		{
			cout << "Please enter the desired accuracy of e: ";
			cin >> input;
			while ((input < 0) || cin.fail()) //checks if number is integer and nonnegative
			{
				cin.clear();
				cin.ignore();
				cout << "Please enter a number that is nonnegative: ";
				cin >> input;
			}
			cout << "The constant e with accuracy " << input << " equals: " << accE(input) << endl;
		}break;
		case 'C': case 'c': //choice C which calls upon function for e^x operation
		{
			cout << "Please enter the desired accuracy of e: ";
			cin >> input;
			while ((input < 0) || cin.fail()) //will not continue until user inputs positive number
			{
				cin.clear();
				cin.ignore();
				cout << "Please enter a number that is nonnegative: ";
				cin >> input;
			}
			cout << "Please enter x: ";
			cin >> inputx;
			while (cin.fail()) //checks if input is valid
			{
				cin.clear();
				cin.ignore();
				cout << "Please enter a number: ";
				cin >> inputx;
			}
			cout << "e^" << inputx << " with accuracy " << input << " is equal to " << etox(input, inputx) << endl;
		} break;
		case '0': //closese program when user inputs 0
			return 0;
			break;
		default: //will be called upon every time a user inputs invalid choice at selection menu
			cout << "You did not enter a valid selection of a, b, or c." << endl;
			break;
		}
	}
}
