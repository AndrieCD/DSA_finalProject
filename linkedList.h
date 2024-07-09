#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    struct Node *next;
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void append(T &newData)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = newData;
        newNode->next = NULL;

        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    /*
     Searches for an element in the list
    bool search(int val)
    {
        // TODO
        Node *nodePtr;

        if (!head)
        {
            return false;
        }
        else
        {
            nodePtr = head;

            while (nodePtr)
            {
                if (nodePtr->data == val)
                {
                    return true;
                }
                nodePtr = nodePtr->next;
            }
        }
        // default return value
        return false;
    }
    */

    void display() const
    {
        Node<T> *temp = head;
        while (temp)
        {
            std::cout << "Item: " << temp->data.itemName << ", Price: " << temp->data.price << ", Stock: " << temp->data.numInStock << std::endl;
            temp = temp->next;
        }
    }
};

#endif