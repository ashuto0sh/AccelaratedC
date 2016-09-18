#include "Vec.hpp"
#include <iostream>
#include <string>

template <typename T>
void print(const Vec<T>& v) {
	typename Vec<T>::const_iterator it = v.begin();
	while (it != v.end()) {
		std::cout << *it++ << std::endl;
	}
}

Vec<std::string> createAndFill() {

	Vec<std::string> v;
	v.push_back("Lalal");
	v.push_back("123");
	v.push_back("Kakak");
	v.push_back("Hahah");

	return v;
}

int main() {
	auto v = createAndFill();
	print(v);

	v.clear();
	std::cout << v.size() << std::endl;

	v.push_back("123");
	v.push_back("234");
	v.push_back("345");

	print(v);

	return 0;
}
