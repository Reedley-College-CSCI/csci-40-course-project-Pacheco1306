// CSCI-40 Final Project
// Author: [Alexis Pacheco]

/*
 Description:
 This program is a calorie tracker. It reads food items from a file,
 allows the user to add new food items, displays all food items,
 calculates total calories, fat, and carbohydrates, and compares
 the total calories to the user's daily calorie goal.
 */




#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct FoodItem {
    string name;
    int calories;
    double fat;
    double carbs;
};

    void displayMenu() {
    cout << endl;
    cout << "===== Calorie Tracker Menu =====" << endl;
    cout << "1. View food items" << endl;
    cout << "2. Add food item" << endl;
    cout << "3. View nutrition summary" << endl;
    cout << "4. Save and exit" << endl;
    cout << "Choose an option: ";
}

int readFoodItems(FoodItem* foods, int* size, int maxSize) {
    ifstream inputFile("calories.txt");

    *size = 0;

    if (!inputFile) {
        cout << "No file found. Starting with an empty food list." << endl;
        return 0;
    }


    while (*size < maxSize) {
        getline(inputFile, (foods + *size)->name);

        if (inputFile.eof()) {
            break;
        }

        inputFile >> (foods + *size)->calories;
        inputFile >> (foods + *size)->fat;
        inputFile >> (foods + *size)->carbs;
        inputFile.ignore();

        (*size)++;
    }

    inputFile.close();
    return 1;
}

void saveFoodItems(FoodItem* foods, int size) {
    ofstream outputFile("calories.txt");

    for (int i = 0; i < size; i++) {
        outputFile << (foods + i)->name << endl;
        outputFile << (foods + i)->calories << endl;
        outputFile << (foods + i)->fat << endl;
        outputFile << (foods + i)->carbs << endl;
    }

    outputFile.close();
}

void addFoodItem(FoodItem* foods, int* size, int maxSize) {
    if (*size >= maxSize) {
        cout << "Food list is full. Cannot add more items." << endl;
        return;
    }

    cin.ignore();

    cout << "Enter food name: ";
    getline(cin, (foods + *size)->name);

    cout << "Enter calories: ";
    cin >> (foods + *size)->calories;

    cout << "Enter fat grams: ";
    cin >> (foods + *size)->fat;

    cout << "Enter carbohydrate grams: ";
    cin >> (foods + *size)->carbs;

    if ((foods + *size)->calories < 0 ||
        (foods + *size)->fat < 0 ||
        (foods + *size)->carbs < 0) {
        cout << "Invalid input. Values cannot be negative." << endl;
        return;
    }

    (*size)++;
    cout << "Food item added successfully." << endl;
}

int main() {
    const int MAX_ITEMS = 100;

    FoodItem* foods = new FoodItem[MAX_ITEMS];
    int size = 0;
    int* sizePtr = &size;

    int calorieGoal;
    int* goalPtr = &calorieGoal;

    int choice;

    readFoodItems(foods, sizePtr, MAX_ITEMS);

    cout << "Enter your daily calorie goal: ";
    cin >> *goalPtr;

    while (*goalPtr <= 0) {
        cout << "Invalid goal. Enter a positive calorie goal: ";
        cin >> *goalPtr;
    }

    delete[] foods;
    return 0;
}
