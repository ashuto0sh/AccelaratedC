#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ios>

using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::vector;

int main(){
	cout<<"Enter the numbers"<<endl;

	vector<double> vec;
	double x;
	while(cin>>x){
		vec.push_back(x);
	}

	sort(vec.begin(), vec.end());

	typedef vector<double>::size_type vec_sz;
	vec_sz sz=vec.size();

	for(vec_sz i=3*sz/4; i<sz;++i){
		cout<<vec[i]<<" ";
	}

	cout<<endl;
	return 0;
}
