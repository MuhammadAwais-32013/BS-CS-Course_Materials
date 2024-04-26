#include<iostream>
using namespace std;
template<class T>
class TreeNode
{
	private:
	 	TreeNode<T> *left;	
		T info;
		TreeNode<T> *right;
	public:
		TreeNode(TreeNode<T> *left, T info, TreeNode<T> *right)
		{
			this->left=left;
			this->info=info;
			this->right=right;
		}
		
		void setLeft(TreeNode<T> *left);
		void setRight(TreeNode<T> *right);
		void setInfo(T info);
		
		TreeNode<T>* getLeft();
		TreeNode<T>* getRight();
		T getInfo();
		
		void displayNode();
};

template<class T>
void TreeNode<T>::setLeft(TreeNode<T> *left)
{
	this->left=left;
}

template<class T>
void TreeNode<T>::setRight(TreeNode<T> *right)
{
	this->right=right;
}

template<class T>
void TreeNode<T>::setInfo(T info)
{
	this->info=info;
}

template<class T>
TreeNode<T>* TreeNode<T>::getLeft()
{
	return this->left;
}

template<class T>
TreeNode<T>* TreeNode<T>::getRight()
{
	return this->right;
}

template<class T>
T TreeNode<T>::getInfo()
{
	return this->info;
}

template<class T>
void TreeNode<T>::displayNode()
{
	cout<<this<<"|"<<this->left<<"|"<<this->info<<"|"<<this->right<<endl;
}

