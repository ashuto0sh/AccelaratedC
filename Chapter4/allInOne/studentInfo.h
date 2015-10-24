#ifndef _STUDENT_INFO_H
#define _STUDENT_INFO_H

#include <vector>
#include <iostream>
#include <string>

struct StudentInfo {
	std::string name;
	double mid;
	double final;
	std::vector<double> hw;
};

bool compare(const StudentInfo &a, const StudentInfo& b);
std::istream& read(std::istream& is, StudentInfo& s);
std::istream& read_hw(std::istream& is, std::vector<double>& hw);

#endif
