#ifndef __Vec_H__
#define __Vec_H__

#include <cstdio>
#include <memory>

template <typename T>
class Vec {
public:
	//Interface
	typedef T value_type;
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;

	Vec() { create(); }
	explicit Vec(size_type n, const T& val=T()) { create(n, val); }

	// Copy constructor
	Vec(const Vec& v) { create(v.begin(), v.end()); }

	// Destructor
	~Vec() { uncreate(); }

	// Assignment Operator
	Vec& operator=(const Vec& v);

	// Index Operator
	value_type & operator[](size_type idx) { return *(data+idx); }
	const value_type & operator[](size_type idx) const{ return *(data+idx); }

	size_type size() const{ return avail-data; }

	// Iterators
	iterator begin() { return data; }
	const_iterator begin() const { return data; }

	iterator end() { return avail; }
	const_iterator end() const { return avail; }

	// push_back as vector::push_back
	void push_back(const T& dat);

	// Erase element pointed by iterator and return the next location
	iterator erase(iterator pos);

	// Clear a Vec but leave the capacity unchanged
	void clear();

private:
	//Implementation
	iterator data;	//first element in the Vec
	iterator limit; //one past the last available element in the vec
	iterator avail;	//one beyond the last constructed element in the Vec

	// Facilities for memory allocation
	std::allocator<T> alloc;

	// Allocate and initialize underlying array
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	// Deallocate and destroy elements
	void uncreate();

	// Support fucntions for push_back
	void grow();
	void unchecked_append(const T&);

};

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec<T>& rhs) {
	if (&rhs != this) {
		uncreate();
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

template <typename T>
void Vec<T>::push_back(const T& val) {
	if (limit == avail){
		grow();
	}
	unchecked_append(val);
}

template <typename T>
void Vec<T>::create() {
	data = avail = limit = 0;
}

template <typename T>
void Vec<T>::create(size_type sz, const T& val) {
	data = alloc.allocate(sz);
	avail = limit = avail + sz;
	uninitialized_fill(data, limit, val);
}

template <typename T>
void Vec<T>::create(const_iterator begin, const_iterator end) {
	auto sz = end-begin;
	data = alloc.allocate(sz);
	limit = avail = uninitialized_copy(begin, end, data);
}

template <typename T>
void Vec<T>::uncreate() {
	if(data) {
		iterator it = avail;
		while(it != data)
			alloc.destroy(--it);
		alloc.deallocate(data, limit-data);
	}
	data = limit = avail = 0;
}

template <typename T>
void Vec<T>::grow() {
	size_type sz = std::max(2*(limit-data), std::ptrdiff_t(1));
	iterator newAlloc = alloc.allocate(sz);
	iterator newAvail = std::uninitialized_copy(data, avail, newAlloc);

	uncreate();

	data=newAlloc;
	avail=newAvail;
	limit=data+sz;
}

template <typename T>
void Vec<T>::unchecked_append(const T& val) {
	alloc.construct(avail++, val);
}

template <typename T>
typename Vec<T>::iterator Vec<T>::erase(iterator it) {
	auto sz = limit-data;
	iterator newData = alloc.allocate(sz);
	auto retIt = uninitialized_copy(data, it, newData);
	auto newAvail=uninitialized_copy(it+1, avail, retIt);

	uncreate();

	data=newData;
	avail=newAvail;
	limit=data+sz;

	return retIt;
}

template <typename T>
void Vec<T>::clear() {
	if (data) {
		iterator it = avail;
		while(it != data)
			alloc.destroy(--it);
	}
	avail = data;
}

#endif
