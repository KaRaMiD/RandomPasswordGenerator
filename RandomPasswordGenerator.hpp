//RandomPasswordGenerator.hpp
#pragma once

#include <string>
#include <unordered_map>
#include <stdexcept>

class RandomPasswordGenerator
{
public:
    RandomPasswordGenerator() = delete;
    ~RandomPasswordGenerator() = delete;

	static std::string GenPassword(const size_t& length, const bool& useSpecialChars = false, const bool& useChars = true,
		const bool& useNumbers = true, bool useUpperChars = true, bool useLowerChars = true);
private:
	static std::string GetAllUpperChars();
	static std::string GetAllLowerChars();

	template<class F>
	static void DeleteFalseBools(std::unordered_map<F, bool>& bools)
	{
		for (auto it = bools.begin(); it != bools.end();)
		{
			if (!it->second)
				it = bools.erase(it);
			else
				it++;
		}
	}
	template<class K, class V>
	static std::pair<const K, V> GetElementByIndex(const std::unordered_map<K, V>& map, const size_t& index)
	{
		if (index >= map.size())
			throw std::out_of_range("index is out of range");

		auto it = map.cbegin();
		std::advance(it, index);

		return *it;
	}
};