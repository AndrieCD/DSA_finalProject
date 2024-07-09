#include <iostream>
#include <fstream>

#include "linkedList.h"

using namespace std;

struct menuItem
{
    string itemName;
    float price;
    int numInStock;
};

void loadMenuItems(LinkedList<menuItem> &menuList)
{
    ifstream inFile("menu.txt");

    if (!inFile.is_open())
    {           // if the file cannot be opened...
        return; // early return, completely stop the function once error is encountered
    }

    std::string itemName;
    float price;
    int numInStock;

    while (getline(inFile, itemName) && inFile >> price >> numInStock)
    {
        menuItem item = {itemName, price, numInStock};
        menuList.append(item);

        inFile.ignore(100, '\n');
    }

    inFile.close();
}

int main()
{
    LinkedList<menuItem> menuList;
    loadMenuItems(menuList);
    menuList.display();

    return 0;
}
