//Purpose of this program is to solve the Towers of Hanoi problem
//The program properly displays correct results, displaying each step in the process

#include <stdio.h>
#include<iostream>
#include<math.h>

using namespace std;
// below are the declarations of each stack, each representing a tower
struct twr1
{
	int data1;
	twr1 *next1;
}*top1 = NULL, *p1 = NULL, *np1 = NULL;

struct twr2
{
	int data2;
	twr2 *next2;
}*top2 = NULL, *p2 = NULL, *np2 = NULL;

struct twr3
{
	int data3;
	twr3 *next3;
}*top3 = NULL, *p3 = NULL, *np3 = NULL;

void push(int data, int y) //pushes a plate, creates a new tower to replace the existing one
{
	switch (y)
	{
	case 1: // pushes from first tower
	{
		np1 = new twr1;
		np1->data1 = data;
		np1->next1 = NULL;
		if (top1 == NULL)
		{
			top1 = np1;
		}
		else
		{
			np1->next1 = top1;
			top1 = np1;
		}
		break;
	}
	case 2: // pushes from second tower
	{
		np2 = new twr2;
		np2->data2 = data;
		np2->next2 = NULL;
		if (top2 == NULL)
		{
			top2 = np2;
		}
		else
		{
			np2->next2 = top2;
			top2 = np2;
		}
		break;
	}
	case 3: // pushes from third tower
	{
		np3 = new twr3;
		np3->data3 = data;
		np3->next3 = NULL;
		if (top3 == NULL)
		{
			top3 = np3;
		}
		else
		{
			np3->next3 = top3;
			top3 = np3;
		}
		break;
	}
	default:
		break;
	}
}
int pull(int x) // pulls a plate
{
	int b = 999;
	switch (x)
	{
	case 1:
	{
		if (top1 == NULL)
		{
			return b;
		}
		else
		{
			p1 = top1;
			top1 = top1->next1;
			return(p1->data1);
			delete(p1);
		}
		break;
	}
	case 2:
	{
		if (top2 == NULL)
		{
			return b;
		}
		else
		{
			p2 = top2;
			top2 = top2->next2;
			return(p2->data2);
			delete(p2);
		}
		break;
	}
	case 3:
	{
		if (top3 == NULL)
		{
			return b;
		}
		else
		{
			p3 = top3;
			top3 = top3->next3;
			return(p3->data3);
			delete(p3);
		}
		break;
	}

	default:
		break;
	}
}

int topStack() // finds top of stack value
{
	if (top1 != NULL && top1->data1 == 1)
	{
		return 1;
	}
	else if (top2 != NULL && top2->data2 == 1)
	{
		return 2;
	}
	else if (top3 != NULL && top3->data3 == 1)
	{
		return 3;
	}
}
void displayTowers() //displays the contents of each stack
{
	cout << endl;
	twr1 *p1;
	p1 = top1;
	cout << "T1\t";
	while (p1 != NULL)
	{
		cout << p1->data1 << "\t";
		p1 = p1->next1;
	}
	cout << endl;
	twr2 *p2;
	p2 = top2;
	cout << "T2\t";
	while (p2 != NULL)
	{
		cout << p2->data2 << "\t";
		p2 = p2->next2;
	}
	cout << endl;
	twr3 *p3;
	p3 = top3;
	cout << "T3\t";
	while (p3 != NULL)
	{
		cout << p3->data3 << "\t";
		p3 = p3->next3;
	}
	cout << endl;
	cout << endl;
}

void solveTowers(int n) //function used to solve for the towers, can solve for many numbers of plates
{
	int a, b, x, i;
	for (i = 0; i < (pow(2, n)); i++)
	{
		displayTowers(); // displays towers for every step
		x = topStack(); // checks where top of stack of value is
		if (i % 2 == 0)
		{
			if (x == 1)
			{
				push(pull(1), 3);
			}
			else if (x == 2)
			{
				push(pull(2), 1);
			}
			else if (x == 3)
			{
				push(pull(3), 2);
			}
		}
		else
		{
			if (x == 1)
			{
				a = pull(2);
				b = pull(3);
				if (a < b && b != 999)
				{
					push(b, 3);
					push(a, 3);
				}
				else if (a > b && a != 999)
				{
					push(a, 2);
					push(b, 2);
				}
				else if (b == 999)
				{
					push(a, 3);
				}
				else if (a == 999)
				{
					push(b, 2);
				}
			}
			else if (x == 2)
			{
				a = pull(1);
				b = pull(3);
				if (a < b && b != 999)
				{
					push(b, 3);
					push(a, 3);
				}
				else if (a > b && a != 999)
				{
					push(a, 1);
					push(b, 1);
				}
				else if (b == 999)
				{
					push(a, 3);
				}
				else if (a == 999)
				{
					push(b, 1);
				}
			}
			else if (x == 3)
			{
				a = pull(1);
				b = pull(2);
				if (a < b && b != 999)
				{
					push(b, 2);
					push(a, 2);
				}
				else if (a > b && a != 999)
				{
					push(a, 1);
					push(b, 1);
				}
				else if (b == 999)
				{
					push(a, 2);
				}
				else if (a == 999)
				{
					push(b, 1);
				}
			}
		}
	}
}

int main()
{
	int n;
	cout << "This program is able to solve the popular Towers of Hanoi problem\n\nEnter the number of plates: ";
	cin >> n;
	while (cin.fail()) { //checks if user inputted valid integer
		cin.clear();
		cin.ignore();
		cout << "Please enter a valid first number: ";
		cin >> n;
	}
	for (int i = n; i >= 1; i--)
	{
		push(i, 1);// calls for this since the first tower is always where the problem starts off
	}
	solveTowers(n);
	cout << "\nPress Enter to exit the program...";
	cin.ignore(); // required due to the use of cin earlier in the program
	cin.get(); // allows for exit upon pressing enter so that answer remains displayed while not in debugging mode
	return 0;
}