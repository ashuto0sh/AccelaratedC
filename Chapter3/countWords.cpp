#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::vector;
using std::sort;
using std::string;
using std::endl;

int main(){
	cout<<"Enter the words"<<endl;

	vector<string> vec;
	string str;

	while(cin>>str){
		vec.push_back(str);
	}

	sort(vec.begin(), vec.end());

	for(vector<double>::size_type i=0;i<vec.size();){
		vector<double>::size_type j=i+1;
		while(j<vec.size() && vec[j]==vec[i])
			j++;
		cout<<vec[i]<<" "<<j-i<<endl;
		i=j;
	}

	return 0;
}
