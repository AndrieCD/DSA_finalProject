#ifndef TREES_H
#define TREES_H

#include <iostream>
using namespace std;

template <typename T>
struct TNode
{
    T data;
    TNode<T> *left, *right;
};

template <typename T>
class Tree
{
private:
    TNode<T> *root;

public:
    Tree()
    {
        root = NULL;
    }

    void insertNode(T &newData)
    {
        TNode<T> *newNode, *nodePtr; // we declare two pointers
                                     // newNode will be responsible for the dynamic creation of nodes
                                     // and nodePtr is to acquire reference to where we are in the tree

        newNode = new TNode<T>;  // this line creates a node
        newNode->data = newData; // this line and the next will assign values to the node's members
        newNode->left = NULL;
        newNode->right = NULL;

        if (!root)
            root = newNode;
        else
        {
            nodePtr = root; // else, we will assign root to nodePtr so that we have a reference on where we are inside the root
            while (nodePtr != NULL)
            { //	we'll now enter a loop that runs while the node we are currently referencing is not empty
                if (newData.GWA < nodePtr->data.GWA)
                {                                // we then compare the value we want to insert to the current node's data
                    if (nodePtr->left)           // if the value is less than the node's data, we'll check the current node's left pointer
                        nodePtr = nodePtr->left; // if the node's left pointer is pointing to another, then we'll replace the reference
                    else
                    {
                        nodePtr->left = newNode; // on the other hand, if the node's left pointer is NULL, we'll assign our newly created node
                        break;
                    }
                }
                else
                {

                    if (nodePtr->right)
                        nodePtr = nodePtr->right;
                    else
                    {
                        nodePtr->right = newNode;
                        break;
                    }
                }
            }
        }
    }

    void inorderTraversal(TNode<T> *nodePtr, int &studNum)
    {
        if (!nodePtr)
        {
            return;
        }
        inorderTraversal(nodePtr->right, studNum);
        cout << "Student " << ++studNum << ": " << nodePtr->data.studentName << endl
             << "       Age: " << nodePtr->data.age << endl
             << " ID Number: " << nodePtr->data.studentNumber << endl
             << "       GWA: " << nodePtr->data.GWA << endl
             << endl;
        inorderTraversal(nodePtr->left, studNum);
    }

    void displayRanking()
    {
        if (!root)
        {
            cout << "Tree is empty!" << endl;
            return;
        }

        int studNum = 0;
        cout << "Displaying: \n";

        inorderTraversal(root, studNum);
    }
};

#endif