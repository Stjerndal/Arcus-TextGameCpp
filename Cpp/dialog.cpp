#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include "dialog.h"

namespace arcus {

	/*
	const std::string statement;
	const std::vector<std::string> answers;
	int latestAnswer;*/

	Dialog::Dialog(const std::string _statement, const std::vector<std::string> _answers)
	: statement(_statement)
	, answers(_answers)
	, latestAnswer(-1)
	{}

	void Dialog::chooseAnswer(int answer) {
		latestAnswer = answer;
	}

	std::string Dialog::present() const {
		std::ostringstream oss;
		oss << '"' << statement << '"' << "\n\nYou say:";
		for(int i = 0; i < answers.size(); ++i) {
			oss << "\n" << i+1 << ". " << '"' << answers[i] << '"';
		}
		return oss.str();
	}

	
}