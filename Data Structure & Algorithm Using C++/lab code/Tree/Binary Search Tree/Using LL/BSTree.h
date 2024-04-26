#include <iostream>
#include "TreeNode.h"
using namespace std;
template <class t>
class BSTree
{

private:
    TreeNode<t> *root;

public:
    BSTree()
    {
        root = 0;
    }

    void Insert(t element);
    void preOrderTraverse(TreeNode<t> *t_root);
    void inOrderTraverse(TreeNode<t> *t_root);
    void postOrderTraverse(TreeNode<t> *t_root);
    TreeNode<t> *getRoot();
    int totalNode(TreeNode<t> *t_root);
    void Search(t element);
    void recursiveSearch(TreeNode<t> *t_root, t element);
    bool isBSTree(TreeNode<t> *t_root);

}; // End of class

template <class T>
bool BSTree<T>::isBSTree(TreeNode<T> *t_root)
{
    if (t_root == 0)
    {
        cerr << "Tree is not Declaraed \n";
        return 0;
    }

    if ((t_root->getInfo() > t_root->getLeft()->getInfo()) && (t_root->getRight()->getInfo() > t_root->getInfo()))
    {
        return 1;
    }

    else if (t_root->getInfo() > t_root->getLeft()->getInfo())
    {
        return isBSTree(t_root->getLeft());
    }

    else
    {
        return isBSTree(t_root->getRight());
    }

    return -1;
}

template <class t>
void BSTree<t>::Insert(t element)
{
    TreeNode<t> *n = new TreeNode<t>(0, element, 0); // left, info ,right
    if (root == 0)
    {
        root = n; // first node
    }

    else
    {
        TreeNode<t> *temp = 0;
        TreeNode<t> *ptr = root; /// start from root/head
        while (ptr != 0)
        {
            if (n->getInfo() == ptr->getInfo()) // error
            {
                cerr << "Duplication is not allowed \n";
                delete n;
                return;
            }

            else if (n->getInfo() < ptr->getInfo()) // info of new node is less than info of old node
            {
                temp = ptr;
                ptr = ptr->getLeft();
            }

            else // n->getInfo()> ptr->getinfo()
            {
                temp = ptr;
                ptr = ptr->getRight();
            }

        } // end of while

        if (n->getInfo() < temp->getInfo()) // info of new node is less than info of old node
        {
            temp->setLeft(n);
        }

        else
        {
            temp->setRight(n);
        }

    } // end of else

} // end of Insert

template <class t>
void BSTree<t>::preOrderTraverse(TreeNode<t> *t_root)
{
    if (t_root != 0)
    {
        t_root->displayTNode();
        // cout<<t_root->getInfo()<<endl;// Root
        preOrderTraverse(t_root->getLeft());  // LST
        preOrderTraverse(t_root->getRight()); // RST
    }

} // End of preorderTraverse

template <class t>
void BSTree<t>::inOrderTraverse(TreeNode<t> *t_root)
{
    if (t_root != 0)
    {
        postOrderTraverse(t_root->getLeft());
        t_root->displayTNode();
        postOrderTraverse(t_root->getRight());
    }

} // End of postOrderTraverse

template <class t>
void BSTree<t>::postOrderTraverse(TreeNode<t> *t_root)
{
    if (t_root != 0)
    {
        postOrderTraverse(t_root->getLeft());
        postOrderTraverse(t_root->getRight());
        t_root->displayTNode();
    }
} // End of inOrderTraverse

template <class t>
TreeNode<t> *BSTree<t>::getRoot()
{
    return this->root;
} // end of getRoot

template <class t>
int BSTree<t>::totalNode(TreeNode<t> *t_root)
{
    if (t_root == 0)
        return 0;
    else if (t_root->getLeft() == 0 && t_root->getRight() == 0)
    {
        return 1;
    }

    else
    {
        return totalNode(t_root->getLeft()) + 1 + totalNode(t_root->getRight());
    }
}

template <class t>
void BSTree<t>::Search(t element)
{
    TreeNode<t> *ptr = root;

    while (ptr != 0 && element != ptr->getInfo())
    {
        if (element < ptr->getInfo())
        {
            ptr = ptr->getLeft();
        }

        else
        {
            ptr = ptr->getRight();
        }
    }

    if (ptr == 0)
    {
        cerr << "Element not Found \n";
    }

    else // found
    {
        cout << "Found at " << ptr << endl;
    }
}

template <class t>
void BSTree<t>::recursiveSearch(TreeNode<t> *t_root, t element)
{
    if (t_root == 0)
    {
        cout << "Not found \n";
    }

    else if (element == t_root->getInfo())
    {
        cout << "Found at " << t_root << endl;
    }

    else if (element < t_root->getInfo())
    {
        recursiveSearch(t_root->getLeft(), element);
    }

    else
    {
        recursiveSearch(t_root->getRight(), element);
    }
}