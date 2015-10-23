#include <iostream>
#include <string>

int main(){
	std::cout<<"Enter your name: ";
	std::string name;
	std::cin>>name;
	std::string greeting="Hello, "+name+"!";

	int pad=4;	//no of paddings to provide for the o/p frame
	int rows=2*pad+3;	//1-greeting 2-top+bottom
	std::cout<<std::endl;

	int r=0;	//number of rows written

	const std::string::size_type cols=2+greeting.size()+pad*2;

	//loop invariant: we have written r rows of o/p so far
	while(r<rows){
		//for induction: assume invariant is true here
		
		int c=0;
		while(c<cols){
			if(r==0 || r==rows-1 || c==0 || c==cols-1){
				std::cout<<"*";
			}else {
				if(r==pad+1 && c==pad+1){
					std::cout<<greeting;
					c+=greeting.size()-1;
				}
				else
					std::cout<<" ";
			}
			++c;
		}
		
		//invariant is false
		std::cout<<std::endl;

		//incrementing r would make the invariant true again
		r++;
	}

	return 0;
}
