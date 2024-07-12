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
        TNode<T> *newNode, *nodePtr;

        newNode = new TNode<T>;
        newNode->data = newData;
        newNode->left = NULL;
        newNode->right = NULL;

        if (!root)
            root = newNode;
        else
        {
            nodePtr = root;
            while (nodePtr != NULL)
            {
                if (newData.GWA < nodePtr->data.GWA)
                {
                    if (nodePtr->left)
                        nodePtr = nodePtr->left;
                    else
                    {
                        nodePtr->left = newNode;
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