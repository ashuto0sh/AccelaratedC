#include <iostream>
#include <string>
#include <ios>
#include <vector>
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
double median(vector<double> vec);

int main(){
	cout<<"Enter your name: ";
	string name;
	cin>>name;
	cout<<"Hello, "+name+"!"<<endl;

	cout<<"Please enter your midterm and final grades";
	double mid, final;
	cin>>mid>>final;

	cout<<"Enter your homework grades followed by end-of-file";

	double x;
	vector<double> homework;	

	/* Little subtleity. using cin as condition in while loop.
	 * The condition passes if we successfully read x. It fails 
	 * on one of 3 ocassions:
	 * 1. Reached end-of-file.
	 * 2. Incompatible input.
	 * 3. H/W failure on input device.
	 */
	while(cin>>x){
		homework.push_back(x);
	}

	streamsize prec=cout.precision();
	//change precision to 3 significant digits
	cout<<"Your final grade is "<<setprecision(3)<<0.2*mid+0.4*final+0.4*median(homework)<<endl;

	return 0;
}

double median(vector<double> vec){
	typedef vector<double>::size_type vec_sz;
	vec_sz sz=vec.size();

	if(sz==0){
		cout<<"Enter your grades "<<endl;
		return 1;
	}
	sort(vec.begin(), vec.end());

	vec_sz mid=sz/2;
	if(sz%2)
		return vec[mid];
	return (vec[mid]+vec[mid-1])/2;
}
