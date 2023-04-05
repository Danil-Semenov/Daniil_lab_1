#pragma once

#include <vector>
#include <string>


class FrequencyCounter {

public:
	FrequencyCounter(const std::string& string_path);

	double GetRussianWordsFrequency() const;
private:
	std::vector<std::string> words_;

	void FillWordsFromFile(const std::string& string_path);

	bool IsRussianWord(const std::string& word) const noexcept;
};