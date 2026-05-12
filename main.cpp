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

int main() {
    return 0;
}
