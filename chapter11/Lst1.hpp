#ifndef __LIST_H__
#define __LIST_H__

#include <exception>
#include <stdexcept>

template <typename T>
class List {
public:
	// Public Interface
	struct Node {
		Node(const T &val, Node* nxt=nullptr): data(val), next(nxt) {}
		T data;
		Node* next;
	};

	List(): head(new Node(0)) {}
	List(const List& other): head(new Node(0)) {
		const Node* tmp = other.begin();
		while (tmp != other.end()) {
			push_front(tmp->data);
			tmp = tmp->next;
		}
		reverse();
	}

	void reverse() {
		Node *i = begin(), *p = nullptr, *n;
		while (i != nullptr) {
			n = i->next;
			i->next = p;
			p = i; i = n;
		}
		head->next = p;
	}

	~List() { clear(); }

	void clear() {
		auto tmp = head->next;
		while (tmp != nullptr) {
			auto tmp2 = tmp->next;
			delete tmp;
			tmp = tmp2;
		}
	}

	Node* find(const T& dat) {
		auto p = head->next;
		while (p != nullptr) 
			if (p -> data == dat)
				break;
		return p;
	}

	Node* begin() { return head->next; }
	Node* end() { return nullptr; }

	const Node* begin() const { return head->next; }
	const Node* end() const { return nullptr; }

	void erase_after(const T& dat) {
		auto p = head->next;
		while (p != nullptr) {
			if (p->data == dat) {
				auto tmp = p->next;
				p->next = p->next->next;
				delete tmp;
			}
		}
	}

	void erase_after(Node* nd) {
		if (nd->next == nullptr)
			return;
		auto tmp = nd->next;
		nd->next=nd->next->next;
		delete tmp;
	}

	void insert_after(Node* nd, const T& dat) {
		Node* tmp = new Node(dat, nd->next);
		nd->next = tmp;
	}

	bool empty() { return head->next == nullptr; }

	T& front() { 
		if (empty())
			throw std::range_error("empty_list");
		return head->next->dat; 
	}

	const T& front() const { 
		if (empty())
			throw std::range_error("empty_list");
		return head->next->dat; 
	}

	void pop_front() {
		if (empty())
			throw std::range_error("empty_list");
		erase_after(head);
	}

	void push_front(const T& dat) {
		insert_after(head, dat);
	}

private:
	// Private Implementation
	Node* head;
};

#endif
