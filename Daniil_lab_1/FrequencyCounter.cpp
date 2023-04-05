#include "FrequencyCounter.h"

#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <algorithm>
#include <iostream>

using namespace std;


FrequencyCounter::FrequencyCounter(const std::string& string_path) {
	FillWordsFromFile(string_path);
}

double FrequencyCounter::GetRussianWordsFrequency() const {
	if (words_.size() == 0) {
		throw runtime_error("���� ����, ���������� ������� ���������.");
	}

	
	double russian_words_amount = count_if(words_.begin(), words_.end(), [this](const std::string& word) {
		return IsRussianWord(word);
		});

	return russian_words_amount / (1.0 * words_.size());
}

void FrequencyCounter::FillWordsFromFile(const std::string& string_path) {
	const filesystem::path path(string_path);

	if (!std::filesystem::is_regular_file(path)) {
		throw logic_error("���� ����� �� � ����� ��� ��������� ���� �� ����������. "s);
	}

	ifstream input(path);

	if (!input.is_open()) {
		throw runtime_error("�� ������� ������� ����. ");
	}
	
	std::string word;
	while (input >> word) {
		words_.push_back(word);
	}

	input.close();
}

bool FrequencyCounter::IsRussianWord(const std::string& word) const noexcept {
	
	auto letter_checker = [](const char letter) {
		return ((int)(letter) == -88 || (int)(letter) == -62)// ��� ���� � � ������ ���������
			|| ((int)(letter) >= -64 && (int)(letter) <= -1);// ��� ���������
	};

	return all_of(word.begin(), word.end(),letter_checker);
}