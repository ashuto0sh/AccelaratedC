#include "Lst1.hpp"
#include <iostream>
int main()
{
	List<int> X;
	X.push_front(3);
	X.push_front(2);
	X.push_front(1);

	for (List<int>::Node* it = X.begin(); it; it = it->next )
		std::cout << it->data << std::endl;

	X.reverse();

	for (List<int>::Node* it = X.begin(); it; it = it->next )
		std::cout << it->data << std::endl;

}
