//Purpose of this program is to teach children multiplication by giving them 2 random numbers and ask for their product
//This program operates as expected with no errors

#include <iostream>
using namespace std;

int main()
{
	int first, second, answer, input; // variables needed for the operation of this program
	bool done = false; //used for the answer checking loop
	while (true)
	{
		first = (rand() % 11); //doing this gives a random number from 0 to 10
		second = (rand() % 11); // this range was chosen since the program is aimed at children
		answer = first * second; // saves the correct answer
		cout << "What is " << first << " times " << second << "?\n";
		cin >> input;
		while (cin.fail()) //checks that input is a number
		{
			cin.clear();
			cin.ignore();
			cout << "Your answer must be a number!\n";
			cin >> input;
		}
		do //loops until a correct answer is given
		{
			if (input == answer) // program continues and asks another question when correct answer is given
			{
				cout << "Very good!\n";
				done = true; // this will allow the loop to exit
			}
			else // program stuck in loop until correct answer
			{
				cout << "No. Please try again.\n";
				cin >> input;
				while (cin.fail()) { // checks for proper input
					cin.clear();
					cin.ignore();
					cout << "Your answer must be a number!\n";
					cin >> input;
				}
			}
		} while (!done); // loop continues until done is set to true
		done = false; // done set to false again after exiting loop so the loop will work again on next question
	}
}