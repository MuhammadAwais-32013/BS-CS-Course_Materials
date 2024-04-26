#include <iostream>
using namespace std;
template <class t>
class TreeNode
{
private:
    TreeNode<t> *left;
    TreeNode<t> *right;
    t info;

public:
    TreeNode(TreeNode<t> *left, t info, TreeNode<t> *right)
    {
        this->left = left;
        this->right = right;
        this->info = info;
    }
    
    void setLeft(TreeNode<t> *left);
    void setRight(TreeNode<t> *right);
    void setInfo (t info);
    TreeNode<t>* getLeft();
    t getInfo();
    TreeNode<t>* getRight();
    void displayTNode();

}; // End of Class TreeNode

template<class t>
void TreeNode<t>::setRight(TreeNode<t> *right)
{
  this->right=right;
}

template<class t>
void TreeNode<t>::setLeft(TreeNode<t> *left)
{
    this->left=left;
}

template<class t>
void TreeNode<t>::setInfo(t info)
{
    this->info=info;
}

template<class t>
TreeNode<t>* TreeNode<t>::getRight()
{
    return this->right;
}// end

template<class t>
TreeNode<t>* TreeNode<t>::getLeft()
{
    return this->left;
}

template<class t>
t TreeNode<t>::getInfo()
{
    return this->info;
}

template<class t>
void TreeNode<t>::displayTNode()
{
  cout<<"|"<<this<<"|"<<this->left<<"|"<<this->info<<"|"<<this->right<<endl;
}