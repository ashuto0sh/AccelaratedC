#include "median.h"
#include <algorithm>
#include <vector>
#include <stdexcept>

using std::vector;
using std::domain_error;
using std::sort;

double median(vector<double> v){
	typedef vector<double>::size_type vec_sz;

	sort(v.begin(), v.end());

	vec_sz sz=v.size();
	if(sz==0)	throw domain_error("Median of an empty vector");

	vec_sz mid=sz/2;
	return sz%2?v[mid]:(v[mid]+v[mid-1])/2;
}
