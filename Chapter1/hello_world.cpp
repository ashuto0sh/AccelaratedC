#include <iostream>
#include <string>

int main(){
	/* contents of std::cout are buffered to be flushed 
	 * only on one out of three ocassions:
	 * 1. When a std::cin follows
	 * 2. When buffer is full
	 * 3. When explicitly told to do so. like writing std::endl
	 */
	std::cout<<"Please enter your first name: ";

	std::string name;
	std::cin>>name;

	std::cout<<"Hello "<<name<<"!"<<std::endl;

	return 0;
}
