#pragma once
#include "Tree.h"
#include <iostream>
#include "QueueVector.h"

using namespace std;


template<class T>
class SearchTree : public Tree<T>
{

public:
	void add(T value);
	bool  search(T value) { return search(Tree<T>::root, value); };
	void remove(T value) { remove(Tree<T>::root, value); };
	typename Tree<T>::Node* min(typename Tree<T>::Node* current);
	typename Tree<T>::Node* max(typename Tree<T>::Node* current);
	T successor(T value) { return successor(Tree<T>::root, value); };
	int height() { return height(Tree<T>::root); };
	void reflect() { reflect(Tree<T>::root); };
	void swap(typename Tree<T>::Node*& current_left, typename Tree<T>::Node*& current_right);
	void deleteDuplicates() { deleteDuplicates(Tree<T>::root); };
	void breadthScan() { breadthScan(Tree<T>::root); };


private:
	void add(typename Tree<T>::Node* current, T val);
	bool search(typename Tree<T>::Node* current, T val);
	void remove(typename Tree<T>::Node* current, T val);
	void remove_(typename Tree<T>::Node* current);
	T successor(typename Tree<T>::Node* current, T val);
	typename Tree<T>::Node* search_(typename Tree<T>::Node* current, T val);// help func
	int height(typename Tree<T>::Node* current);
	void reflect(typename Tree<T>::Node* current);//help func
	void deleteDuplicates(typename Tree<T>::Node* current);
	void breadthScan(typename Tree<T>::Node* current);




};

template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);
}

template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	if (current->value < val)
		// add to right subtree
		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(current, val);
			return;
		}
		else add(current->right, val);
	else if (current->value > val)
		// add to left subtree
		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(current, val);
			return;
		}
		else add(current->left, val);
	else
	{
		(current->count++);
		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(current, val);
			return;
		}
		else add(current->left, val);
	}

}

template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

template<class T>
void SearchTree<T>::remove_(typename Tree<T>::Node* current)
{
	typename Tree<T>::Node* q = current;
	typename Tree<T>::Node* z = q;
	if (q->left == nullptr && q->right == nullptr) z = q;// has no sons
	if (q->left != nullptr && q->right != nullptr) z = search_(current, successor(q->value));// has 2 sons
	q->value = z->value;             //erease 
	typename Tree<T>::Node* y;
	if (z->left != nullptr)y = z->left;
	else y = z->right;
	if (y != nullptr) y->parent = z->parent;
	typename Tree<T>::Node* p;
	p = z->parent;
	if (z == p->left) p->left = y;
	else p->right = y;
	return;
}

template <class T>
typename Tree<T>::Node* SearchTree<T>::min(typename Tree<T>::Node* current) {
	while (current->left != nullptr)
		current = current->left;
	return current;
}

template <class T>
typename Tree<T>::Node* SearchTree<T>::max(typename Tree<T>::Node* current) {
	while (current->right != NULL)
		current = current->right;
	return current;
}

template<class T>
int SearchTree<T>::height(typename Tree<T>::Node* current)
{
	if (!current)
		return 0;
	else {
		// Find the height of both subtrees
		// and use the larger one
		int left_height = height(current->left);
		int right_height = height(current->right);
		if (left_height >= right_height)
			return left_height + 1;
		else
			return right_height + 1;
	}
}

template<class T>
void SearchTree<T>::reflect(typename Tree<T>::Node* current)
{
	if (!current)return;
	reflect(current->left);   //Go down to the end of the tree with a left sub tree
	reflect(current->right); //Go down to the end of the tree with a right sub tree
	swap(current->left, current->right);  //change node
}

template<class T>
void SearchTree<T>::deleteDuplicates(typename Tree<T>::Node* current)
{
	static typename Tree<T>::Node* p = current;
	if (current)
	{
		deleteDuplicates(current->left);
		deleteDuplicates(current->right);
		if (current->count > 1) remove_(current);

	}
}

//template<class T>
//void SearchTree<T>::remove(typename Tree<T>::Node* current, T val)
//{
//	if (!search(val)) throw "no such number\n";
//	typename Tree<T>::Node* q = search_(current, val);
//	if (!(q->parent)&&!(q->left)&&!(q->right)) {
//		this->clear();
//		return;
//	}
//	typename Tree<T>::Node* z = q;
//	if (q->left == nullptr && q->right == nullptr) z = q;// has no sons.
//	if (q->left != nullptr && q->right != nullptr)  z = search_(current, successor(current, search_(current, val)->value));// has 2 sons
//	q->value = z->value;             //erease 
//	typename Tree<T>::Node* y;
//	if (z->left != nullptr)y = z->left;
//	else y = z->right;
//	if (y != nullptr) y->parent = z->parent;
//	typename Tree<T>::Node* p;
//	p = z->parent;
//	if (z == p->left) p->left = y;
//	else p->right = y;
//	return;
//}


template <class T>
void SearchTree<T>::remove(typename Tree<T>::Node* current, T val) {
	typename Tree<T>::Node* z, * y, * q, * p = search_(current, val);

	if (!p->left || !p->right) //if he has  son
		z = p;
	else
		z = min(p->right);  //if he has 2 sons
	p->value = z->value;//put value in our current that we want to delete

	if (z->left)//if he has left son we keep him else we keep the right
		y = z->left;
	else
		y = z->right;
	if (y)      //have son, father of z point on y
		y->parent = z->parent;
	q = z->parent;// new point on father of z to check if z is right son or left

	if (z == q->left)  //if z is left son so his left parent point on y (null or son of z)else the oposit
		q->left = y;
	else
		q->right = y;
}

template<class T>
T SearchTree<T>::successor(typename Tree<T>::Node* current, T val)
{
	if (!search(val)) {
		throw "no successor\n";
	}// no such node
	typename Tree<T>::Node* current_ = search_(current, val); //our node
	if (max(current) == current_->value)throw "no successor\n";
	if (current_->right != nullptr) // if our node has right son
		return min(current_->right);

	else // has no right son
	{
		if (current_->parent == nullptr) {
			throw "no successor\n";
		}
		typename Tree<T>::Node* p = current_->parent;

		while (!(p->parent == nullptr))
		{
			if (p->value > current_->value) return p->value;//if the parent is a left son of his parent
			else {
				p = p->parent;
				current_ = current_->parent;
			}
		}
	}
}

template<class T>
void SearchTree<T>::swap(typename Tree<T>::Node*& current_left, typename Tree<T>::Node*& current_right)
{

	typename Tree<T>::Node* tmp = current_left; //swap
	current_left = current_right;
	current_right = tmp;

}

template <class T>
typename Tree<T>::Node* SearchTree<T>::search_(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		throw "ERROR::not found";	// not found
	if (current->value == val)
		return current;
	if (current->value < val)
		return search_(current->right, val);
	else
		return search_(current->left, val);
}

template<class T>
void SearchTree<T>::breadthScan(typename Tree<T>::Node* current)
{
	QueueVector<typename Tree<T>::Node*> q(100);

	if (current != nullptr)	q.enqueue(current);
	while (!(q.isEmpty()))
	{
		current = q.dequeue();
		cout << current->value << " ";

		if (current->left != nullptr) q.enqueue(current->left);


		if (current->right != nullptr) q.enqueue(current->right);
	}
}