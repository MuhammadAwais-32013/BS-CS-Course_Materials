#include <iostream>
#include "TreeNode.h"
using namespace std;
template <class T>
class LinkedTree
{
private:
	TreeNode<T> *root;

public:
	LinkedTree()
	{
		root = 0;
	}
	void insert(T element);											// C
	void preOrder(TreeNode<T> *t_root);								// C
	TreeNode<T> *getRoot();											// C
	TreeNode<T> *searchRecursively(TreeNode<T> *t_root, T element); // c
	int recursiveSum(TreeNode<T> *T_root);
	TreeNode<T> *search(T element); // C
	TreeNode<T> *findParent(T element);
	TreeNode<T> *findRightSuccessor(TreeNode<T> *t_root);
	TreeNode<T> *findLeftSuccessor(TreeNode<T> *t_root);
	void deleteNode(T element);
	int totalNodes(TreeNode<T> *t_root);
	bool isBSTree(TreeNode<T> *t_root); //  Lab Exam to check is binary search Tree
};

template <class T>
bool LinkedTree<T>::isBSTree(TreeNode<T> *t_root)
{
	if (t_root == nullptr)
	{
		return true;
	}

	if ((t_root->getLeft() != nullptr && t_root->getInfo() <= t_root->getLeft()->getInfo()) ||
		(t_root->getRight() != nullptr && t_root->getInfo() >= t_root->getRight()->getInfo()))
	{
		return false;
	}

	return isBSTree(t_root->getLeft()) && isBSTree(t_root->getRight());
}

template <class T>
void LinkedTree<T>::insert(T element)
{
	TreeNode<T> *n = new TreeNode<T>(0, element, 0); // L,info,R
	if (this->root == 0)
	{
		root = n;
	}
	else
	{
		TreeNode<T> *temp = 0;
		TreeNode<T> *ptr = root;
		while (ptr != 0)
		{
			if (n->getInfo() == ptr->getInfo())
			{
				cerr << "Duplications are not allowed \n";
				return;
			}
			else if (n->getInfo() < ptr->getInfo())
			{
				temp = ptr;
				ptr = ptr->getLeft();
			}
			else // n->getInfo()>ptr->getInfo()
			{
				temp = ptr;
				ptr = ptr->getRight();
			}
		} // while
		if (n->getInfo() < temp->getInfo())
			temp->setLeft(n);
		else
			temp->setRight(n);
	}
} // insert

template <class T>
void LinkedTree<T>::preOrder(TreeNode<T> *t_root)
{
	if (t_root != 0)
	{
		t_root->displayNode();
		preOrder(t_root->getLeft());
		preOrder(t_root->getRight());
	}
} // preOrder

template <class T>
TreeNode<T> *LinkedTree<T>::getRoot()
{
	return this->root;
}

template <class T>
TreeNode<T> *LinkedTree<T>::search(T element)
{
	TreeNode<T> *ptr = root;
	while (ptr != 0 && ptr->getInfo() != element)
	{
		if (ptr->getInfo() > element)
			ptr = ptr->getLeft();
		else
			ptr = ptr->getRight();
	}
	if (ptr == 0)
	{
		return 0;
	}
	else
	{
		// cout<<"found at"<<ptr<<"\n";
		return ptr;
	}
} // search

template <class T>
TreeNode<T> *LinkedTree<T>::searchRecursively(TreeNode<T> *t_root, T element)
{
	if (t_root == 0)
	{
		// cout<<"Not found \n";
		return 0;
	}

	if (t_root->getInfo() == element)
	{
		// cout<<"found \n";
		return t_root;
	}

	else if (t_root->getInfo() > element)
	{
		return searchRecursively(t_root->getLeft(), element);
	}
	else
	{
		return searchRecursively(t_root->getRight(), element);
	}

} // searchRecursively

template <class T>
int LinkedTree<T>::recursiveSum(TreeNode<T> *t_root)
{
	if (t_root == 0)
		return 0;
	else
		return t_root->getInfo() + recursiveSum(t_root->getLeft()) + recursiveSum(t_root->getRight());
}

template <class T>
TreeNode<T> *LinkedTree<T>::findParent(T element)
{
	TreeNode<T> *parent = 0;
	TreeNode<T> *ptr = root;
	while (ptr != 0 && ptr->getInfo() != element)
	{
		parent = ptr;
		if (ptr->getInfo() > element)
			ptr = ptr->getLeft();
		else
			ptr = ptr->getRight();
	}
	if (ptr == 0)
	{
		return 0;
	}
	else
	{
		// cout<<"found at"<<ptr<<"\n";
		return parent;
	}
} // findParent

template <class T>
TreeNode<T> *LinkedTree<T>::findRightSuccessor(TreeNode<T> *t_root) // RST
{
	TreeNode<T> *ptr = t_root->getRight();
	while (ptr->getLeft() != 0)
	{
		ptr = ptr->getLeft();
	}
	return ptr;
}

template <class T>
TreeNode<T> *LinkedTree<T>::findLeftSuccessor(TreeNode<T> *t_root) // RST
{
	TreeNode<T> *ptr = t_root->getLeft();
	while (ptr->getRight() != 0)
	{
		ptr = ptr->getRight();
	}
	return ptr;
}

template <class T>
void LinkedTree<T>::deleteNode(T element)
{
	if (root == 0)
	{
		cout << "Impossible to delete \n";
		return;
	}
	else
	{
		TreeNode<T> *loc = search(element);
		TreeNode<T> *p_loc = findParent(element);
		if (loc != 0) // value is present so we can delete
		{
			if (loc->getLeft() == 0 && loc->getRight() == 0) // no child
			{
				if (element < p_loc->getInfo())
					p_loc->setLeft(0);
				else
					p_loc->setRight(0);
				delete loc;
			}
			else if ((loc->getLeft() != 0 && loc->getRight() == 0) || (loc->getLeft() == 0 && loc->getRight() != 0)) // one child
			{
				TreeNode<T> *s_child = 0;
				if ((loc->getLeft() != 0 && loc->getRight() == 0))
					s_child = loc->getLeft();
				else
					s_child = loc->getRight();

				if (loc == p_loc->getRight())
					p_loc->setRight(s_child);

				else
					p_loc->setLeft(s_child);
				delete loc;
			}
			else // 2 children
			{
				TreeNode<T> *sloc = findSuccessor(loc);
				TreeNode<T> *p_sloc = findParent(sloc->getInfo());
				sloc->setLeft(loc->getLeft());
				sloc->setRight(loc->getRight());

				if (sloc == p_sloc->getLeft())
					p_sloc->setLeft(0);

				else
					p_sloc->setRight(0);

				if (loc == p_loc->getLeft())
					p_loc->setLeft(sloc);
				else
					p_loc->setRight(sloc);

				delete loc;
			}
		} // if
	}
} // delete

template <class T>
int LinkedTree<T>::totalNodes(TreeNode<T> *t_root)
{
	if (t_root->getLeft() == 0 && t_root->getRight() == 0)
		return 1;
	else
		return totalNodes(t_root->getLeft()) + 1 + totalNodes(t_root->getRight());
} // totalNodes
