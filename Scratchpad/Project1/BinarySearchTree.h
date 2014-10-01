#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <memory>
#include <vector>
#include <iostream>

template<typename T> 
class BinarySearchTree {
	struct Node;
	using node_ptr = std::unique_ptr <Node>;
	node_ptr root;
public:
	using value_type = T;

	void insert(const value_type& value);
	void remove(const value_type& value);

	void traverse();

private:
	struct Node {
		Node(value_type d) : data(d), left(nullptr), right(nullptr) {}
		value_type data;
		node_ptr left;
		node_ptr right;
	};
	
	node_ptr insert_(node_ptr& root, const value_type& value);
	void traverse_preorder(node_ptr& node);
	void traverse_inorder(node_ptr& node);
	void traverse_postorder(node_ptr& node);
};

template<typename T>
typename BinarySearchTree<T>::node_ptr BinarySearchTree<T>::insert_(node_ptr& root, const value_type& value) {
	if (!root) {
		root = node_ptr(new Node(value));
	}
	else if (value < root->data) {
		root->left = (insert_(root->left, value));
	}
	else if (value > root->data) {
		root->right = (insert_(root->right, value));
	}
	return std::move(root);
}

template <typename T>
void BinarySearchTree<T>::insert(const value_type& value) {
	root = std::move(insert_(root, value));
}


template <typename T>
void BinarySearchTree<T>::traverse() {
	std::cout << "The pre-order traversal is: ";
	traverse_preorder(root);
	std::cout << std::endl << "The in-order traversal is: ";
	traverse_inorder(root);
	std::cout << std::endl << "The post-order traversal is: ";
	traverse_postorder(root);
}


template <typename T>
void BinarySearchTree<T>::traverse_preorder(node_ptr& node) {
	if (!node) return;

	std::cout << node->data << ", ";
	traverse_inorder(node->left);
	traverse_inorder(node->right);
}

template <typename T>
void BinarySearchTree<T>::traverse_inorder(node_ptr& node) {
	if (!node) return;

	traverse_inorder(node->left);
	std::cout << node->data << ", ";
	traverse_inorder(node->right);
}

template <typename T>
void BinarySearchTree<T>::traverse_postorder(node_ptr& node) {
	if (!node) return;

	traverse_inorder(node->left);
	traverse_inorder(node->right);
	std::cout << node->data << ", ";
}

#endif