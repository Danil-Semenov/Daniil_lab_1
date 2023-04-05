#pragma once

#include <cassert>
#include <string>

#include "LogDuration.h"
#include "FrequencyCounter.h"

constexpr double EPSILON = 0.000001;

void CheckCorrectFile(const std::string& path_to_file, double expected) {

	try {
		FrequencyCounter counter(path_to_file);
		assert(abs(counter.GetRussianWordsFrequency() - expected) < EPSILON);
	}
	catch(const std::exception& exc){
		//
	}

}

void CheckIncorrectFile(const std::string& path_to_file) {
	double exceptions = 0;
	try {
		FrequencyCounter counter(path_to_file);
		double frequency = counter.GetRussianWordsFrequency();
	}
	catch (const std::exception& exc) {
		exceptions++;
	}

	assert(exceptions == 1);
}

void RunTests() {
	std::cout << "Запуск тестов..." << std::endl;

	CheckCorrectFile("..\\tests\\0.5.txt",0.5);
	CheckCorrectFile("..\\tests\\0.1.txt", 0.1);
	CheckCorrectFile("..\\tests\\0.txt", 0.0);
	CheckCorrectFile("..\\tests\\1.txt", 1);

	CheckIncorrectFile("..\\tests\\empty.txt");
	CheckIncorrectFile("..\\tests\\not_existing.txt");

	std::cout << "Все тесты прошли!" << std::endl;
}