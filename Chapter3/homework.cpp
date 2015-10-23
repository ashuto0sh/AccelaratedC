#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::setprecision;
using std::streamsize;

int main(){
	cout<<"Enter your name: ";
	string name;
	cin>>name;
	cout<<"Hello, "+name+"!"<<endl;

	cout<<"Please enter your midterm and final grades";
	double mid, final;
	cin>>mid>>final;

	cout<<"Enter your homework grades followed by end-of-file";

	int cnt=0;
	double sum=0, x;

	/* Little subtlity. using cin as condition in while loop.
	 * The condition passes if we successfully read x. It fails 
	 * on one of 3 ocassions:
	 * 1. Reached end-of-file.
	 * 2. Incompatible input.
	 * 3. H/W failure on input device.
	 */
	while(cin>>x){
		sum+=x;
		cnt++;
	}

	streamsize prec=cout.precision();
	//change precision to 3 significant digits
	cout<<"Your final grade is "<<setprecision(3)<<0.2*mid+0.4*final+0.4*sum/cnt<<setprecision(prec)<<endl;

	return 0;
}
