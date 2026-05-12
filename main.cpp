// CSCI-40 Final Project
// Author: [Alexis Pacheco]

/* 
 * Description:
 *
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

int main() {
    return 0;
}
