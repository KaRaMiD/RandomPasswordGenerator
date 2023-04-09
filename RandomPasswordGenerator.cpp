//RandomPasswordGenerator.cpp
#include "RandomPasswordGenerator.hpp"

#include <ctime>
#include <cstdlib>

std::string RandomPasswordGenerator::GenPassword(const size_t& length, const bool& useSpecialChars, const bool& useChars, const bool& useNumbers, bool useUpperChars, bool useLowerChars)

{
	if (!useSpecialChars && !useUpperChars && !useLowerChars && !useNumbers && !useChars)
		throw std::exception("all bools are false");

	if (!useChars)
	{
		useUpperChars = false;
		useLowerChars = false;
	}

	const std::string special = "/.,&*()^%$#@!|\\=+-_[];:\'\"<> ";
	const std::string upperChars = GetAllUpperChars();
	const std::string lowerChars = GetAllLowerChars();
	const std::string nums = "1234567890";

	std::string pass;

	std::unordered_map<std::string, bool> chars = { {lowerChars, useLowerChars}, {upperChars, useUpperChars},
		{nums, useNumbers}, {special, useSpecialChars} };
	DeleteFalseBools(chars);

	srand(time(0));

	for (size_t i = 0; i < length; i++)
	{
		const unsigned char random = rand() % chars.size();
		const auto symbols = GetElementByIndex(chars, random).first;
		const size_t randomChar = rand() % symbols.size();

		pass.push_back(symbols[randomChar]);
	}

	return pass;
}
std::string RandomPasswordGenerator::GetAllUpperChars()
{
	std::string upper;
	
	for (unsigned char i = 'A'; i <= 'Z'; i++)
	{
		upper.push_back(i);
	}
	return upper;
}
std::string RandomPasswordGenerator::GetAllLowerChars()
{
	std::string lower;
	for (unsigned char i = 'a'; i <= 'z'; i++)
	{
		lower.push_back(i);
	}
	return lower;
}