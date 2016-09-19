#ifndef __LIST_H__
#define __LIST_H__

/* 
 * Note: Copied as is from http://www.panix.com/~elflord/cpp/list_howto/. 
 * Please head over to the link for a great intro to iterators.
 */

#include <iostream>
#include <algorithm>
#include <iterator>

template <typename T>
class List {
private:
	// Private Implementation
	struct Node {
		Node(const T& val, Node* n = nullptr): data(val), next(n) {}
		T data;
		Node* next;
	};
	Node* m_head;

public:
	// Public Interface
	class Iterator
		: public std::iterator<std::forward_iterator_tag, T> 
	{
	public:
		friend class List;
		friend class Const_Iterator;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer;

		Iterator(Node* n = nullptr) { m_curr = n; }
		Iterator(const Iterator& it) { m_curr = it.m_curr; }

		Iterator& operator=(const Iterator& rhs) { m_curr = rhs.m_curr; return *this; }

		Iterator& operator++() {
			m_curr = m_curr->next;
			return *this;
		}

		Iterator operator++(int) {
			auto retIt = *this;
			m_curr = m_curr->next;
			return retIt;
		}

		reference operator*() { return m_curr->data; }
		pointer operator->() { return m_curr; }

		bool operator==(const Iterator& rhs) const { return this->m_curr == rhs->m_curr; }
		bool operator!=(const Iterator& rhs) const { return m_curr!=rhs.m_curr; }

	private:
		Node *m_curr;
	};

	class Const_Iterator
		: public std::iterator<std::forward_iterator_tag, const T> 
	{
	public:
		friend class List;
		friend class Iterator;
		typedef T& reference;
		typedef const T& const_reference;
		typedef const T* const_pointer;
	
		Const_Iterator(const Node* n = nullptr) { m_curr = n; }
		Const_Iterator(const Iterator& it) { m_curr = it.m_curr; }
		Const_Iterator(const Const_Iterator& it) { m_curr = it.m_curr; }

		Const_Iterator& operator=(const Const_Iterator& rhs) {
			this->m_curr = rhs.m_curr;
			return *this;
		}
		Const_Iterator& operator=(const Iterator& rhs) {
			this->m_curr = rhs.m_curr;
			return *this;
		}

		const_reference operator*() { return m_curr->data; }
		const_pointer operator->() { return m_curr; }

		Const_Iterator& operator++() {
			m_curr = m_curr->next;
			return *this;
		}

		Const_Iterator operator++(int) {
			auto retIt = *this;
			m_curr = m_curr->next;
			return retIt;
		}

		bool operator==(const Const_Iterator& rhs) { return m_curr == rhs.m_curr; }
		bool operator!=(const Const_Iterator& rhs) const { return m_curr!=rhs.m_curr; }

	private:
		const Node *m_curr;
	};

	typedef Iterator iterator;
	typedef Const_Iterator const_iterator;
	typedef T& reference;
	typedef const T& const_reference;
	typedef T* pointer;

	List(Node* n = nullptr) : m_head(n) {}
	List(const List& other) : m_head(0) {
		const_iterator it = other.begin();
		while (it != other.end()) {
			push_front(*it++);
		}
		reverse();
	}

	~List() { clear(); }

	void clear() {
		Node* tmp = m_head;
		while (tmp != nullptr) {
			Node* ttmp = tmp->next;
			delete tmp;
			tmp = tmp->next;
		}
		m_head = nullptr;
	}

	void swap(List& rhs) {
		std::swap(m_head, rhs.m_head);
	}

	List& operator=(const List& rhs) {
		clear();
		List tmp = rhs; // initialization.
		swap(tmp);
		return *this;
	}

	void reverse() {
		Node *p = nullptr, *i = m_head, *t;
		while (i != nullptr) {
			t = i->next;
			i->next = p;
			p = i; i = t;
		}
		m_head = p;
	}

	void push_front(const T& dat) {
		Node* tmp = new Node(dat, m_head);
		m_head = tmp;
	}

	void pop_front() {
		if (m_head == nullptr)
			throw std::domain_error("empty_list");
		Node* tmp = m_head;
		m_head = m_head->next;
		delete tmp;
	}

	reference front() {
		if (m_head == nullptr)
			throw std::domain_error("empty_list");
		return m_head->data;
	}

	const_reference front() const {
		if (m_head == nullptr)
			throw std::domain_error("empty_list");
		return m_head->data;
	}

	iterator begin() { return iterator(m_head); }
	const_iterator begin() const { return const_iterator(m_head); }

	iterator end() { return iterator(nullptr); }
	const_iterator end() const { return const_iterator(nullptr); }

	void erase_after(iterator& it) {	// A lot of assumptions!
		Node* node = it.m_curr;
		Node* tmp = node->next;
		node->next = tmp->next;
		delete tmp;
	}

	void insert_after(iterator& it, const T& dat) {
		Node* node = it.m_curr;
		Node* tmp = new Node(dat, node->next);
		node->next = tmp;
	}

	bool empty() { return (m_head == nullptr); }
};

#endif
