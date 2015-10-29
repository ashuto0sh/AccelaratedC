#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <string>

double median(std::vector<double> vec);
double grade(double m, double final, std::vector<double> homework);

class StudentInfo {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
	std::istream& read_hw(std::istream& in);
public:
	StudentInfo();
	StudentInfo(std::istream& );
	std::istream& read(std::istream&);
	std::string getName() const{ return name; }
	double grade() const;
	bool valid() const{ return !homework.empty(); }
};

StudentInfo::StudentInfo(): midterm(0), final(0){ }

StudentInfo::StudentInfo(std::istream& in){
	in>>name;
	in>>final>>midterm;
	read_hw(in);
}

std::istream& StudentInfo::read(std::istream& in){
	in>>name;
	in>>midterm>>final;
	return read_hw(in);
}

std::istream& StudentInfo::read_hw(std::istream& in){
	if(in){
		double x;
		while(in>>x)
			homework.push_back(x);
		in.clear();
	}
	return in;
}

double StudentInfo::grade() const{
	return ::grade(midterm, final, homework);
}

bool compare(const StudentInfo& x, const StudentInfo& y){
	return x.getName() < y.getName();
}

double grade(double m, double final, std::vector<double> homework){
	return 0.2*m+0.4*final+0.4*::median(homework);
}

double median(std::vector<double> vec){
	sort(vec.begin(), vec.end());
	std::vector<double>::size_type sz=vec.size();

	if(sz==0)	throw std::domain_error("Enter yoyur hw grades");

	return sz%2?vec[sz/2]:(vec[sz/2]+vec[sz/2-1])/2;
}

using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::max;
using std::string;
int main(){
	vector<StudentInfo> students;
	StudentInfo record;
	string::size_type maxlen=0;

	//read and store the data
	while(record.read(cin)){
		students.push_back(record);
		maxlen=max(maxlen, record.getName().length());
	}

	sort(students.begin(), students.end(), compare);

	for(vector<StudentInfo>::size_type i=0;i<students.size();++i){
		try{
			double grade=students[i].grade();
			cout<<"Hello, "<<students[i].getName()<<", Your grade is "<<grade<<endl;
		} catch(domain_error e){
			cout<<e.what()<<endl;
		}
	}
	
	return 0;
}
