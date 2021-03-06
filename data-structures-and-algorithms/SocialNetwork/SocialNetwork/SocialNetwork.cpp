//Purpose of this program is to create a simple command line social network
//This program operates as expected with minimal errors

#include <iostream>
#include <string>
#include "Abdugram.h"

using namespace std;

int j = 0; //initialize counter at 0, used for counter
Abdugram acnt[20]; //This social network will allow 20 accounts

void MainMenu(int profile); //fkn prototype
void menu1();

int exit() {
	_exit(0);
}

int findUser() { //returns array index associated with name. 
	string searchname;
	cout << "Enter name:" << endl;
	cin >> searchname;
	for (int i = 0; i < 20; i++) {

		if (acnt[i].getName() == searchname) {
			cout << acnt[i].getName() << " has been added to your friend list." << endl;
			cout << "Status: " << acnt[i].getStatus() << "\nAge: " << acnt[i].getAge() << "\nProfile picture URL: " << acnt[i].getPP() << endl;
			return i; //is used in many functions
		}
		if (i == 19 && acnt[i].getName() != searchname) //if by the last iteration the name still isnt found, retry
		{
			cout << "User not found." << endl;
			menu1();
		}

	}

}

void menu1() { //starts off program with option to sign in or logi in
	int x;
	cout << "1. Login\n2. New User\nEnter any other number to exit" << endl;
	cin >> x;
	while (cin.fail()) { // checks for proper input
		cin.clear();
		cin.ignore();
		cout << "Please input a number\n";
		cin >> x;
	}
	switch (x)
	{
	case 1:
	{
		int a = findUser(); //sets the array index to returned int associated with name
		acnt[a].loginAcc(); //calls signIn funtion within the array object
		MainMenu(a); //goes to main menu for more function selection
	} break;
	case 2:
	{
		::j++; //updates global array j
		acnt[::j].newAcc(); //calls create profile class fxn
		MainMenu(::j);  //goes to main menu for more function selection
	} break;
	default:
		exit();
		break;
	}

}

void MainMenu(int profile) { //profile is the array index assocaited with object
	int choice2;
	cout << "What would you like to do?" << endl;
	cout << "1. Edit your profile\n2. Add a Friend\n3. Update your status\n4. Logout" << endl;
	cin >> choice2;
	while (cin.fail()) { // checks for proper input
		cin.clear();
		cin.ignore();
		cout << "Please input a number\n";
		cin >> choice2;
	}
	switch (choice2) { //switch case to allow each entered number to send a different function
	case 1: {
		acnt[profile].newAcc();
		MainMenu(profile); // will send to mainmenu recursion until the signout option is chosen
	}
	case 2: {
		findUser();
		acnt[profile].addAcc();
		MainMenu(profile);
	}
	case 3: {
		acnt[profile].newStatus();
		MainMenu(profile);
	}
	case 4: {
		cout << "You are now signed out." << endl; //after sign out will return to main menu
		menu1();
	}

	}

}

int main()
{
	cout << "\t\tAbdugram\n" << endl; //social network logo
	menu1(); //starts with first menu
}