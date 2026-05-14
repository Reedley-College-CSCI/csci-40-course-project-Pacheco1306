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
    return 0;
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


void displayFoodItems(FoodItem* foods, int size) {
    if (size == 0) {
        cout << "No food items have been recorded." << endl;
        return;
    }

    cout << endl;
    cout << left << setw(20) << "Food"
         << setw(12) << "Calories"
         << setw(10) << "Fat"
         << setw(10) << "Carbs" << endl;

    cout << "--------------------------------------------------" << endl;

    for (int i = 0; i < size; i++) {
        cout << left << setw(20) << (foods + i)->name
             << setw(12) << (foods + i)->calories
             << setw(10) << (foods + i)->fat
             << setw(10) << (foods + i)->carbs << endl;
    }
}

int getTotalCalories(FoodItem* foods, int size) {
    int total = 0;

    for (int i = 0; i < size; i++) {
        total += (foods + i)->calories;
    }

    return total;
}

double getTotalFat(FoodItem* foods, int size) {
    double total = 0;

    for (int i = 0; i < size; i++) {
        total += (foods + i)->fat;
    }

    return total;
}

double getTotalCarbs(FoodItem* foods, int size) {
    double total = 0;

    for (int i = 0; i < size; i++) {
        total += (foods + i)->carbs;
    }

    return total;
}

void displaySummary(FoodItem* foods, int size, int calorieGoal) {
    int totalCalories = getTotalCalories(foods, size);
    double totalFat = getTotalFat(foods, size);
    double totalCarbs = getTotalCarbs(foods, size);

    cout << fixed << setprecision(1);
    cout << endl;
    cout << "===== Nutrition Summary =====" << endl;
    cout << "Daily calorie goal: " << calorieGoal << endl;
    cout << "Total calories eaten: " << totalCalories << endl;
    cout << "Total fat: " << totalFat << "g" << endl;
    cout << "Total carbohydrates: " << totalCarbs << "g" << endl;

    if (totalCalories > calorieGoal) {
        cout << "You went over by "
             << totalCalories - calorieGoal
             << " calories." << endl;
    }
    else if (totalCalories < calorieGoal) {
        cout << "You are under by "
             << calorieGoal - totalCalories
             << " calories." << endl;
    }
    else {
        cout << "You met your calorie goal exactly." << endl;
    }
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

    do {
        displayMenu();
        if(!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
        }

        if (choice == 1) {
            displayFoodItems(foods, *sizePtr);
        }
        else if (choice == 2) {
            addFoodItem(foods, sizePtr, MAX_ITEMS);
        }
        else if (choice == 3) {
            displaySummary(foods, *sizePtr, *goalPtr);
        }
        else if (choice == 4) {
            saveFoodItems(foods, *sizePtr);
            cout << "Food items saved. Exiting program." << endl;
        }
        else {
            cout << "Invalid menu option. Please try again." << endl;
        }

    } while (choice != 4);

    delete[] foods;
    return 0;
}
