// CS303_Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <stdexcept>  // For exception handling
#include "Functions.h"  // Function prototypes

using namespace std;

int main() {
    int NumbersArray[MAX_SIZE] = { 0 };
    int size = 0;       
    string filename = "A1input.txt";  
    int user_choice = 0;

    readDataFromFile(NumbersArray, size, filename);

    cout << "Welcome to the one-dimensional array program." << endl;

    do {
        cout << "\n1. Add Integer\n";
        cout << "2. Remove Integer\n";
        cout << "3. Find Integer\n";
        cout << "4. Modify Integer\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> user_choice;

        switch (user_choice) {
        case 1:
            try {
                int add_newValue;

                cout << "Please input what value you would like to add to the array: ";
                while (!(cin >> add_newValue)) {
                    throw invalid_argument("Invalid input. Please enter a numeric value: ");
                }

                addInteger(NumbersArray, size, add_newValue);
                cout << "Integer added successfully." << endl;
            }
            catch (const invalid_argument& e) {
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //get rid of invalid input
            }
            catch (const exception& e) {
                cerr << "Unexpected error: " << e.what() << endl;
            }
            break;
        case 2:
            //removeInteger function
            int remove_index;
            cout << "Please enter desired index of element to remove: ";
            
            while (!(cin >> remove_index) || remove_index < 0 || remove_index >= size) {
                cout << "Invalid input. Please enter a valid index (0 to " << size - 1 << "): ";
                cin.clear();  //clear error
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  //get rid of invalid input
            }

            removeInteger(NumbersArray, size, remove_index);
            break;
        case 3:
            //findInteger function
            int value;
            cout << "Please enter value you wish to find: ";

            while (!(cin >> value)) {
                cout << "Invalid input. Please enter a numeric value: ";
                cin.clear();  //clear error
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  //get rid of invalid input
            }

            findInteger(NumbersArray, size, value);
            break;
        case 4:
            int modify_index;
            int modify_newValue;

            try {
                cout << "Please enter the index of the integer you wish to modify: ";
                while (!(cin >> modify_index) || modify_index < 0 || modify_index >= size) {
                    throw invalid_argument("");  // Throw an exception if input is invalid
                }

                cout << "Please enter the new value you would like at this index: ";
                while (!(cin >> modify_newValue)) {
                    throw invalid_argument("");  // Throw an exception if input is invalid
                }

                modifyInteger(NumbersArray, size, modify_index, modify_newValue);
            }
            catch (const invalid_argument&) {
                cerr << "Invalid input. Please enter a valid index (0 to " << size - 1 << ") and a numeric value." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear invalid input
            }
            catch (const exception& e) {
                cerr << "Unexpected error: " << e.what() << endl;
            }
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (user_choice != 5);

    return 0;
}


