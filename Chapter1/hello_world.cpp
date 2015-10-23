#include <iostream>
#include <string>

int main(){
	std::cout<<"Please enter your first name: ";
	std::string name;
	std::cin>>name;

	std::string greeting="Hello, "+name+"!";

	std::string spaces(greeting.length()+2, ' ');
	std::cout<<std::string(greeting.length()+4, '*')<<std::endl;
	std::cout<<"*"+spaces+"*"<<std::endl;
	std::cout<<"* "+greeting+" *"<<std::endl;
	std::cout<<"*"+spaces+"*"<<std::endl;
	std::cout<<std::string(greeting.length()+4, '*')<<std::endl;

	return 0;
}
