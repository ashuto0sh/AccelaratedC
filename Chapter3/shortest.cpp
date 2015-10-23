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

	vector<string>::size_type s_idx=0, l_idx=0;
	for(vector<double>::size_type i=1;i<vec.size();++i){
		if(vec[i].length() < vec[s_idx].length())
			s_idx=i;
		else if(vec[i].length() > vec[l_idx].length())
			l_idx=i;
	}

	cout<<"Shortest: "<<vec[s_idx]<<endl;
	cout<<"Longest: "<<vec[l_idx]<<endl;

	return 0;
}
