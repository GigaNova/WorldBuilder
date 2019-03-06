#pragma once
#include <random>

class NumberHelper
{
public:
	static std::vector<int> getRandomNumbers(int t_amount, int t_min, int t_max)
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<double> range(t_min, t_max + 1);
		std::vector<int> randomNumbers;

		int diff = abs(t_max - t_min);
		if (diff < t_amount) return randomNumbers;

		while(randomNumbers.size() < t_amount)
		{
			int randomNumber = range(mt);
			if (std::find(randomNumbers.begin(), randomNumbers.end(), randomNumber) == randomNumbers.end()) {
				randomNumbers.push_back(randomNumber);
			}
		}

		return randomNumbers;
	}
};
