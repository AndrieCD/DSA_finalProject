#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
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

    void updateFile()
    {
        Node<T> *current = head;
        ofstream outFile("studentList.txt");

        current = head;

        while (current)
        {
            outFile << current->data.studentName << endl
                    << current->data.age << endl
                    << current->data.studentNumber << endl
                    << current->data.GWA << endl;

            current = current->next;
        }
        outFile.close();
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

    void deleteRecord(const string &toSearch)
    {
        Node<T> *current = head;
        Node<T> *prev = NULL;

        if (!current)
        {
            cout << "NO RECORDS AVAILABLE..." << endl
                 << endl;
            system("pause");
            return;
        }

        while (current)
        {
            if (current->data.studentName == toSearch)
            {
                if (current != head)
                {
                    prev->next = current->next;
                    delete current; // deletes the node
                    cout << "Record Deleted!\n";
                    return;
                }
                else
                {
                    head = current->next;
                    delete current;
                    cout << "Record Deleted!\n";
                    return;
                }
            }
            prev = current;
            current = current->next;
        }

        cout << toSearch << " was not found!\n";
        return;
    }

    int listSize()
    {
        int size = 0;
        Node<T> *nodePtr = head;

        while (nodePtr)
        {
            size++;
            nodePtr = nodePtr->next;
        }
        return size;
    }

    void bubbleSortAscending()
    {
        int n = listSize();
        for (int i = 0; i < n - 1; ++i)
        {
            Node<T> *nodePtr = head;
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (nodePtr->data.studentName > nodePtr->next->data.studentName)
                {
                    T temp = nodePtr->data;
                    nodePtr->data = nodePtr->next->data;
                    nodePtr->next->data = temp;
                }
                nodePtr = nodePtr->next;
            }
        }
    }

    void bubbleSortDescending()
    {
        int n = listSize();
        for (int i = 0; i < n - 1; ++i)
        {
            Node<T> *nodePtr = head;
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (nodePtr->data.studentName < nodePtr->next->data.studentName)
                {
                    T temp = nodePtr->data;
                    nodePtr->data = nodePtr->next->data;
                    nodePtr->next->data = temp;
                }
                nodePtr = nodePtr->next;
            }
        }
    }

    void search(const string &toSearch)
    {
        Node<T> *nodePtr = head;
        if (!nodePtr)
        {
            cout << "The list is empty!";
            return;
        }
        while (nodePtr)
        {
            if (nodePtr->data.studentName == toSearch)
            {
                cout << "Student Found!" << endl
                     << endl
                     << "   Student: " << nodePtr->data.studentName << endl
                     << "       Age: " << nodePtr->data.age << endl
                     << " ID Number: " << nodePtr->data.studentNumber << endl
                     << endl;
                return;
            }
            nodePtr = nodePtr->next;
        }
        cout << toSearch << " was not found!";
        return;
    }

    void traversalDisplay(Node<T> *nodePtr, int studNum)
    {
        if (!nodePtr)
        {
            return;
        }

        cout << "Student " << studNum << ": " << nodePtr->data.studentName << endl
             << "      Age: " << nodePtr->data.age << endl
             << "ID Number: " << nodePtr->data.studentNumber << endl
             << "      GWA: " << nodePtr->data.GWA << endl
             << endl;
        traversalDisplay(nodePtr->next, ++studNum);
    }

    void display()
    {
        if (!head)
        {
            cout << "The list is empty!";
            return;
        }
        int studNum = 1;
        traversalDisplay(head, studNum);
    }
};

#endif