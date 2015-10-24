#include "studentInfo.h"

#include <iostream>
#include <stdexcept>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::domain_error;
using std::istream;

bool compare(StudentInfo& a, StudentInfo& b){
	return a.name<b.name;
}

istream& read(istream& is, vector<double>& v){
	if(is){
		is.clear();

		double x;
		while(is>>x)
			v.push_back(x);

		is.clear();
	}
	return is;
}

istream& read(istream& is, StudentInfo& s){
	is>>s.name;
	is>>s.mid>>s.final;

	return read(is, s.hw);
}
