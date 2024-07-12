#include <iostream>
#include <fstream>
#include <cstdlib>

#include "linkedList.h"
#include "trees.h"

using namespace std;

struct studentInfo
{
    string studentName;
    int age;
    unsigned int studentNumber;
    float GWA;

    void getData()
    {
        cout << "Enter Student's Name: ";
        getline(cin, studentName);

        cout << "Enter Student's Age: ";
        cin >> age;

        cout << "Enter Student's ID Number: ";
        cin >> studentNumber;

        cout << "Enter Student's GWA: ";
        cin >> GWA;
    }
};

void pauseClear()
{ // code is for pausing and clearing the screen
    system("pause");
    system("cls");
}

void loadstudentInfos(LinkedList<studentInfo> &studentList, Tree<studentInfo> &ranking)
{
    ifstream inFile("studentList.txt");

    if (!inFile.is_open())
    {
        return;
    }

    std::string studentName;
    int age;
    unsigned int studentNumber;
    float GWA;

    while (getline(inFile, studentName) && inFile >> age >> studentNumber >> GWA)
    {
        studentInfo student = {studentName, age, studentNumber, GWA};
        studentList.append(student);
        ranking.insertNode(student);

        inFile.ignore(100, '\n');
    }

    inFile.close();
}

void addNewRecord(LinkedList<studentInfo> &studentList, studentInfo student, char sortType)
{
    ofstream outFile("studentList.txt", ios::app);

    studentList.append(student);

    outFile
        << student.studentName << endl
        << student.age << endl
        << student.studentNumber << endl
        << student.GWA << endl;

    outFile.close();
    cout << "Student Added!\n";
}

void mainMenu(int &menuChoice)
{

    // textual displays about the program and the options that can be made
    do
    {
        cout << "---------------------------------------------------------------------------" << endl
             << "                           STUDENT INFORMATION SYSTEM" << endl
             << "---------------------------------------------------------------------------" << endl
             << endl

             << "What do you want to do?" << endl
             << "1. Add New Record" << endl
             << "2. Search Record" << endl
             << "3. Display All Records" << endl
             << "4. Sort Records" << endl
             << "5. Delete Record" << endl
             << "6. Show Ranking" << endl
             << "7. Exit" << endl
             << endl;

        cout << "Your Input Here: "; // input prompt

        // INPUT VALIDATION
        do
        {
            while (!(cin >> menuChoice))
            { // Repeat until a valid integer input is received.
                cout << "Enter a valid numeric input: ";
                cin.clear();
                cin.ignore(123, '\n');
            }

            if (menuChoice > 7 || menuChoice < 1)
            {                                            // If the input does not fall inside the menu's available options...
                cout << "Enter a valid numeric input: "; // prompt the user to enter a valid input.
            }

        } while (menuChoice > 7 || menuChoice < 1); // Repeat the loop until a valid input is acquired.

        if (menuChoice == 7)
            break;

    } while (menuChoice < 1 || menuChoice > 7); // run the program as long as the user's input is out of bounds or invalid

    system("cls"); // clears the screen after successful input
}

void viewRanking(Tree<studentInfo> ranking)
{
    ranking.displayRanking();
}

void autoSort(LinkedList<studentInfo> studentList, char sortType)
{
    if (sortType == 'A')
    {
        studentList.bubbleSortAscending();
    }
    else if (sortType == 'Z')
    {
        studentList.bubbleSortDescending();
    }
}

int main()
{
    LinkedList<studentInfo> studentList;
    studentInfo studentData;
    Tree<studentInfo> ranking;

    int menuChoice;
    string toSearch;
    char sortType = 'A';

    loadstudentInfos(studentList, ranking);

    do
    {

        mainMenu(menuChoice); // run the mainMenu function to display it on the screen

        switch (menuChoice)
        { // depending on the user's input in mainMenu(), menuChoice will go through the switch case
        case 1:
            cout << "---------------------------------------------" << endl
                 << "                  Add Record                 " << endl
                 << "---------------------------------------------" << endl
                 << endl;
            cin.clear();
            cin.ignore(123, '\n');
            studentData.getData();
            addNewRecord(studentList, studentData, sortType);
            autoSort(studentList, sortType);
            studentList.updateFile();
            pauseClear();
            break;

        case 2:
            cout << "---------------------------------------------" << endl
                 << "                Search Record                " << endl
                 << "---------------------------------------------" << endl
                 << endl;

            cout << "Search by name: ";

            cin.clear();
            cin.ignore(123, '\n');
            getline(cin, toSearch);

            studentList.search(toSearch);
            pauseClear();
            break;

        case 3:
            cout << "=====================================================" << endl
                 << "                   DISPLAY RECORDS                   " << endl
                 << "=====================================================" << endl
                 << endl;
            studentList.display(); // display all records
            pauseClear();
            break;

        case 4:
            cout << "=====================================================" << endl
                 << "                    SORT RECORDS                     " << endl
                 << "=====================================================" << endl
                 << endl;
            cout << "Type A to sort students from A-Z\n"
                 << "Type Z to sort students from Z-A\n";
            cout << "Your Input Here: "; // input prompt
            char input;
            cin >> input;
            if (input == 'A' || input == 'a')
            {
                studentList.bubbleSortAscending();
                sortType = 'A';
                cout << "Sorting is Successful!\n";
            }
            else if (input == 'Z' || input == 'z')
            {
                studentList.bubbleSortDescending();
                sortType = 'Z';
                cout << "Sorting is Successful!\n";
            }
            else
                cout << "Sorting is Unsuccessful!\n";
            pauseClear();
            break;
        case 5:
            cout << "=====================================================" << endl
                 << "                Delete Record" << endl
                 << "=====================================================" << endl
                 << endl;
            cin.clear();
            cin.ignore(123, '\n');
            cout << "Enter the name of the student: ";
            getline(cin, toSearch);
            studentList.deleteRecord(toSearch);
            autoSort(studentList, sortType);
            studentList.updateFile();
            pauseClear();
            break;
        case 6:
            cout << "=====================================================" << endl
                 << "                      SHOW RANKING                   " << endl
                 << "=====================================================" << endl
                 << endl;
            viewRanking(ranking);
            pauseClear();
            break;

        case 7:
            cout << "MEMBERS: " << endl
                 << "Casuga, Nolan Simon" << endl
                 << "Detera, Andrie" << endl
                 << "Regero, Angelito Jose" << endl;
            break; // breaks the do-while loop for program exit
        }
    } while (menuChoice != 7);

    return 0;
}
