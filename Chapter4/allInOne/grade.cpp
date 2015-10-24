#include "studentInfo.h"
#include "median.h"
#include "grade.h"
#include <vector>

using std::vector;

double grade(StudentInfo& s){
	return grade(s.mid, s.final, s.hw);
}

double grade(double mid, double final, vector<double>& hw){
	return grade(mid, final, median(hw));
}

double grade(double mid, double final, double hw){
	return 0.2*mid+0.4*final+0.4*hw;
}
