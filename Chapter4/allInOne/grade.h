#ifndef _GRADE_H
#define _GRADE_H

#include "studentInfo.h"
#include "median.h"
#include <vector>

double grade(StudentInfo& s);
double grade(double, double, std::vector<double>);
double grade(double, double, double);

#endif
