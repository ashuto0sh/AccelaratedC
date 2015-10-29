#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iomanip>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::isspace;
using std::endl;
using std::sort;

vector<string> split(string s){
	vector<string> ret;
	int i, j;

	for(i=0;i<s.size();){
		while(i<s.size() && isspace(s[i]))	i++;
		j=i;
		while(j<s.size() && !isspace(s[j])){
			j++;
		}
		if(j!=i)
			ret.push_back(s.substr(i, j-i));
		i=j;
	}

	return ret;
}

int main(){
	string s;
	while(getline(cin, s)){
		vector<string> v=split(s);

		for(int i=0;i<v.size();++i)
			cout<<v[i]<<endl;

	}

	return 0;

}
