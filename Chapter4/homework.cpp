#include <iostream>
#include <string>
#include <ios>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::setprecision;
using std::streamsize;
using std::vector;
using std::sort;
using std::istream;
using std::domain_error;
double median(vector<double> vec);
istream& read_hw(istream& is, vector<double>& v);
double grade(double mid, double final, const vector<double>& hw);

int main(){
	cout<<"Enter your name: ";
	string name;
	cin>>name;
	cout<<"Hello, "+name+"!"<<endl;

	cout<<"Please enter your midterm and final grades"<<endl;
	double mid, final;
	cin>>mid>>final;

	cout<<"Enter your homework grades followed by end-of-file"<<endl;
	double x;
	vector<double> homework;	
	read_hw(cin, homework);

	try{
		streamsize prec=cout.precision();
		double g = grade(mid, final, homework);
		//change precision to 3 significant digits
		cout<<"Your final grade is ";
		cout<<setprecision(3)<<g<<endl;
	}catch(domain_error){
		cout<<"Enter your grades"<<endl;
	}
	return 0;
}

istream& read_hw(istream& is, vector<double>& v){
	if(is){
		is.clear();

		double x;
		while(is>>x)
			v.push_back(x);

		is.clear();
	}
	return is;
}

double median(vector<double> vec){
	typedef vector<double>::size_type vec_sz;
	vec_sz sz=vec.size();

	if(sz==0){
		throw domain_error("Enter your grades");
	}
	sort(vec.begin(), vec.end());

	vec_sz mid=sz/2;
	if(sz%2)
		return vec[mid];
	return (vec[mid]+vec[mid-1])/2;
}

double grade(double mid, double final, const vector<double>& hw){
	return 0.2*mid+0.4*final+0.4*median(hw);
}
