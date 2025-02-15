#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

const int MAX_SIZE = 100;  //maximum size of the array

void readDataFromFile(int arr[], int& size, const string& filename);
void addInteger(int arr[], int& size, int newValue);
int findInteger(const int arr[], int size, int value);
void modifyInteger(int arr[], int size, int index, int newValue);
bool removeInteger(int arr[], int& size, int index);


#endif
