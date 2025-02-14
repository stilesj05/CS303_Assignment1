#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

const int MAX_SIZE = 100;  //maximum size of the array

// PRE: `filename` is a valid file containing integers, `arr` has enough space to store the data, and `size` is initialized.
// POST: Reads integers from `filename` into `arr`, updates `size` to reflect the number of integers read.
void readDataFromFile(int arr[], int& size, const string& filename);

// PRE: `size < MAX_SIZE` to prevent overflow, `arr` is properly initialized, `newValue` is a valid integer.
// POST: Adds `newValue` to the end of `arr` and increments `size`. Throws an exception if the array is full.
void addInteger(int arr[], int& size, int newValue);

// PRE: `arr` contains `size` valid elements, `size > 0`, `value` is the integer to search for.
// POST: Returns the index of `value` in `arr` if found, otherwise returns -1.
int findInteger(const int arr[], int size, int value);

// PRE: `arr` contains `size` valid elements, `size > 0`, `index` is a valid index (0 ≤ index < size).
// POST: Updates `arr[index]` with `newValue`, preserving all other elements.
void modifyInteger(int arr[], int size, int index, int newValue);

// PRE: `arr` contains `size` valid elements, `size > 0`, `index` is a valid index (0 ≤ index < size).
// POST: Removes `arr[index]` by shifting elements left, decrements `size`, and returns true if successful. Returns false if `index` is invalid.
bool removeInteger(int arr[], int& size, int index);


#endif
