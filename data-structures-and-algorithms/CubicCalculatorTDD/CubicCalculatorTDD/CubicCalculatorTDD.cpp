//Unit Test Practice on simple cubic calculator program

#include <iostream>
#include <ios>
#include <limits>

float cubic(float d) {
	return d * d * d;
}

int main()
{
	char z = '1';
	do {
		float x = 0;
		std::cout << "Enter a number to find its cube value: ";
		std::cin >> x;
		while (std::cin.fail()) { //checks if user inserted a valid integer
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Please enter a valid number: ";
			std::cin >> x;
		}
		std::cout << x << "^3=" << cubic(x) << std::endl;
		std::cout << "Enter any character to continue, or 0 to exit: ";
		std::cin >> z;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (z != '0');
	return 0;
}