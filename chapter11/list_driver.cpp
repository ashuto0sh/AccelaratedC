#include "List.hpp"
#include <algorithm>
#include <numeric>
#include <iostream>

	template <class T>
void print(const List<T> & x)
{
	std::copy(x.begin(), x.end(), std::ostream_iterator<T>(std::cout,"\n"));
}

int main()
{
	List<int> x;
	x.push_front(3);
	x.push_front(4);
	x.push_front(9);
	print(x);
	List<int>::iterator it = std::find(x.begin(),x.end(),9);
	if (it != x.end())
		std::cout << *it << std::endl;

	x.insert_after (it,11);
	std::cout << "The list is" << std::endl;
	print (x);

	int sum = std::accumulate ( x.begin(),x.end(),0);
	int sumsq = std::inner_product( x.begin(),x.end(),x.begin(),0);

	std::cout << "sum " << sum << std::endl;
	std::cout << "sum sq " << sumsq << std::endl;



	std::cout << "Copying ... " << std::endl;
	List<int> y(x);

	print (y);
	std::cout << "Done with copy" << std::endl;

	List<int>::const_iterator cit;
	std::cout << "** ";
	for (cit = y.begin(); cit != y.end(); ++cit) 
		std::cout << *cit << ' '; std::cout << std::endl;

}
