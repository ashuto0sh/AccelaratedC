#include "median.h"
#include "studentInfo.h"
#include "grade.h"
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <ios>
#include <stdexcept>

using std::vector;
using std::endl;
using std::cout;
using std::cin;
using std::istream;
using std::sort;
using std::domain_error;
using std::streamsize;
using std::setprecision;

int main(){
	vector<StudentInfo> students;
	StudentInfo tmp;

	while(read(cin, tmp))
		students.push_back(tmp);

	sort(students.begin(), students.end(), compare);

	for(vector<double>::size_type i=0;i<students.size();i++){
		cout<<students[i].name<<endl;
		
		try{
			double final_grade=grade(students[i]);
			streamsize prec=cout.precision();
			cout<<setprecision(3)<<final_grade<<setprecision(prec)<<endl;
		}catch(domain_error e){
			cout<<e.what()<<endl;
		}
		cout<<endl;
	}

	return 0;
}
