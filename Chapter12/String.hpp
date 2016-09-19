#ifndef __STRING_H__
#define __STRING_H__

#include "../chapter11/Vec.hpp"
#include <cstring>
#include <fstream>
#include <iostream>

class Str {
public:
	// Public Interface
	typedef Vec<char>::size_type size_type;
	typedef Vec<char>::iterator iterator;
	typedef Vec<char>::const_iterator const_iterator;
	typedef char value_type;
	
	/* Constructors */
	Str() {}

	Str(char c, size_type n): data(n, c) { }

	Str(const Str& other): data(other.data) {}

	Str(const char* cp) {
		std::copy(cp, cp+strlen(cp), std::back_inserter(data));
	}

	template <typename In>
	Str(In b, In e) {
		std::copy(b, e, std::back_inserter(data));
	}
	/* End Constructors */

	~Str() { data.clear(); }

	void clear() { data.clear(); }

	char& operator[](size_type i) { return data[i]; }
	const char& operator[] (size_type i) const { return data[i]; }

	iterator begin() { return data.begin(); }
	const_iterator begin() const { return data.begin(); }

	iterator end() { return data.end(); }
	const_iterator end() const { return data.end(); }

	size_type size() const { return data.size(); }

	void push_back(char c) {
		data.push_back(c);
	}

	Str& operator+=(const Str& rhs) {
		std::copy(rhs.begin(), rhs.end(), std::back_inserter(data));
		return *this;
	}

private:
	// Private Implementation
	Vec<char> data;
};

std::ostream& operator<<(std::ostream& out, const Str& str) {
	auto it = str.begin();
	while (it != str.end())
		out << *it++;
	return out;
}

std::istream& operator>>(std::istream& is, Str& str) {
	str.clear();	// obliterate existing data

	char c;
	while (is.get(c) && isspace(c))	;

	auto it = std::back_inserter(str);

	if (is){
		do {
			*it = c;
		} while (is.get(c) && !isspace(c));

		if (is)
			is.unget();
	}
	return is;
}

Str operator+(const Str& lhs, const Str& rhs) {
	Str tmp = lhs;
	tmp += rhs;
	return tmp;
}

#endif
