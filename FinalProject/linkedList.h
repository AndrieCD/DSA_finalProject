#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    // Inserts an element at the beginning of the list
    void insertAtBeginning(int val)
    {
        // TODO
        Node *newNode, *nodePtr;

        newNode = new Node;
        newNode->data = val;

        if (!head)
        {
            head = newNode;
            newNode->next = NULL;
        }
        else
        {
            nodePtr = head;
            head = newNode;
            newNode->next = nodePtr;
        }
    }

    // Inserts an element at a specific position
    void insertAfter(int val, int pos)
    {
        Node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            if (temp == NULL)
            {
                return;
            }
            temp = temp->next;
        }
        Node *newNode = new Node;
        newNode->data = val;
        if (temp == NULL)
        { // If position is at the end of the list
            newNode->next = NULL;
            Node *last = head;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = newNode;
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Inserts an element at the end of the list
    void insert(int val)
    {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Removes the element at a specified location from a non-empty list
    void removeAt(int pos)
    {
        Node *temp1 = head;
        if (pos == 1)
        {
            head = temp1->next;
            delete temp1;
            return;
        }
        for (int i = 1; i < pos - 1; i++)
        {
            temp1 = temp1->next;
        }
        Node *temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }

    // Searches for an element in the list
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

    // Returns the number of elements in the list
    int getSize()
    {
        // TODO
        Node *nodePtr;
        int size = 0;

        if (!head)
        {
            return size;
        }
        else
        {
            nodePtr = head;

            while (nodePtr)
            {
                size++;
                nodePtr = nodePtr->next;
            }
        }
        return size;
    }

    // Returns true if the list is empty, otherwise returns false
    bool isEmpty()
    {
        return head == NULL;
    }

    // Returns true if the list is full, otherwise returns false
    bool isFull()
    {
        // TODO
        Node *newNode;
        newNode = new Node;

        if (newNode == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Displays the elements in the list
    void printList()
    {
        // TODO
        Node *nodePtr;

        if (!head)
        {
            cout << "The list is empty!" << endl;
        }
        else
        {
            nodePtr = head;
            while (nodePtr)
            {
                cout << nodePtr->data << " ";
                nodePtr = nodePtr->next;
            }
            cout << endl;
        }
    };
};

#endif