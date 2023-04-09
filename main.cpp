//main.cpp
#include <iostream>

#include "RandomPasswordGenerator.hpp"

int main()
{
	try
	{
		size_t size = 0;
		while (!size)
		{
			std::cout << "put the size of password: ";
			std::cin >> size;
			std::cout << std::endl;
		}

		bool useLowerChars = true;
		bool useUpperChars = true;
		bool useNums = true;
		bool useSpecialChars = false;
		bool useSymbols = true;

		char setUpVarsManually = false;
		std::cout << "would you like to set up all chars manually? (y/n): ";
		std::cin >> setUpVarsManually;
		if (setUpVarsManually == 'y')
		{
			std::cout << "use symbols(1/0): ";
			std::cin >> useSymbols;
			if(useSymbols)
			{
				std::cout << "use lower nums(1/0): ";
				std::cin >> useLowerChars;
				std::cout << "use upper nums(1/0): ";
				std::cin >> useUpperChars;
			}
			std::cout << "use nums(1/0): ";
			std::cin >> useNums;
			std::cout << "use special characters nums(1/0): ";
			std::cin >> useSpecialChars;
		}
		std::cout << "your password is: " << RandomPasswordGenerator::GenPassword(size, useSpecialChars, useSymbols, useNums, useUpperChars, useLowerChars);
	}
	catch (const std::exception& e)
	{
		std::cerr << "error: " << e.what();
	}

	return 0;
}