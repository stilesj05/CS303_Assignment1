#include "Functions.h"

void readDataFromFile(int arr[], int& size, const string& filename) {
    ifstream file(filename);  //open file
    if (!file) {
        throw runtime_error("Error: Unable to open file " + filename);
    }

    while (file >> arr[size]) {  //get size
        size++;
    }

    file.close(); 
}

void addInteger(int arr[], int& size, int newValue) {
    //A function that adds a new integer to the end of the array
    if (size >= MAX_SIZE) { //check if array is full
        throw overflow_error("Array is full, cannot add an integer.");
    }

    arr[size] = newValue; //add new value to array if not full
    size++;
}

int findInteger(const int arr[], int size, int value) {
	//A function to check if a certain integer exists in the array. If the number is present, return the index where the number is present.
    for (int i = 0; i < size; i++) {  
        if (arr[i] == value) {
            cout << "Number is found at index " << i << endl;
            return i;  //found the value, return the index
        }
    }
    cout << value << " is not a value in this array." << endl;
    return -1;  //return -1 to indicate not found
}

void modifyInteger(int arr[], int size, int index, int newValue) {
	//A function that can modify the value of an integer when called with the index of the integer in the array and return the new value and old value back to the user.
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds.");
    }

    int oldValue = arr[index];
    arr[index] = newValue;

    cout << "Old value at index " << index << " is " << oldValue << endl;
    cout << "New value at index " << index << " is " << newValue << endl;
}

bool removeInteger(int arr[], int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Error: Index is out of bounds for the size of the array (too big or too small of an index given)." << endl;
        return false;  //failure
    }

    for (int i = index; i < size - 1; i++) { //shift elements to left to overwrite unwanted element
        arr[i] = arr[i + 1];
    }

    size--; //adjust size for removal of the integer
    cout << "Value at given index has successfully been removed." << endl;
    return true;  //success
}



