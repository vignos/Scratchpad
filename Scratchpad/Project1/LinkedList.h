#pragma once

#include <memory>
#include <iostream>

template <typename T>
class LinkedList
{
public:
	using value_type = T;
	using size_type = std::size_t;

	LinkedList() {};
	~LinkedList() {};
	void push_back(const value_type&);
	void pop_back();
	void push_front(const value_type&);
	void pop_front();
	void print() const;
	void print_reverse() const;
	void sort();
	size_type size() const;
	T& operator[](const int index) const;
	LinkedList& operator=(const LinkedList&) = delete;
	LinkedList(const LinkedList&) = delete;
	void clear();
private:
	struct Node
	{
		Node(value_type data = 0) : value(data) {}
		value_type value;
		std::shared_ptr<Node> next;
		std::shared_ptr<Node> previous;
	};
	std::shared_ptr<Node> head;
	size_type ssize;

};

template <typename T>
void LinkedList<T>::push_back(const value_type& value)
{
	std::shared_ptr<Node> new_node = std::make_shared<Node>(value);

	if (head) {
		auto end = head->previous;
		end->next = new_node;
		new_node->previous = end;
	}
	else {
		head = std::make_shared<Node>();
		head->next = new_node;
	}
	new_node->next = head;
	head->previous = new_node;
	ssize++;
}

template <typename T>
void LinkedList<T>::pop_back()
{
	if (head) {
		auto end = head->previous;
		auto new_end = end->previous;
		new_end->next = head;
		head->previous = new_end;
		ssize--;
	}
	else {}
}

template <typename T>
void LinkedList<T>::push_front(const value_type& value)
{
	std::shared_ptr<Node> new_node = std::make_shared<Node>(value);

	if (head) {
		auto front = head->next;
		front->previous = new_node;
		new_node->next = front;
	}
	else {
		head = std::make_shared<Node>();
		new_node->next = head;
		head->previous = new_node;
	}

	new_node->previous = head;
	head->next = new_node;
	ssize++;
}

template <typename T>
void LinkedList<T>::pop_front()
{
	if (head) {
		auto front = head->next;
		auto new_front = front->next;
		head->next = new_front;
		new_front->previous = head;
		ssize--;
	}
}


template <typename T>
void LinkedList<T>::print() const 
{
	auto t = head;
	if (head) {
		while (t->next != head) {
			t = t->next;
			std::cout << t->value << std::endl;
		}
	}

}

template <typename T>
void LinkedList<T>::print_reverse() const
{
	auto t = head;
	if (head) {
		while (t->previous != head) {
			t = t->previous;
			std::cout << t->value << std::endl;
		}
	}

}

using size_type = std::size_t;
template <typename T>
size_type LinkedList<T>::size() const {
	return ssize;
}


template <typename T>
void LinkedList<T>::clear() {
	size = 0;
	head = nullptr;
}

template <typename T>
T& LinkedList<T>::operator[](const int index) const {
	auto n = head->next;
	for (int i = 0; i < index; i++) {
		n = n->next;
	}
	return n->value;
}