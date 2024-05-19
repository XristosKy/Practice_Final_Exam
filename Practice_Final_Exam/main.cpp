/** \file bugExample.cpp
 *  \brief     A Final Exam Practice
 *  \details   Solve The Solution
 *  \author    -
 *  \version   0.1
 *  \date      -
 *  \bug       -
 *  \copyright University of Nicosia.
*/
#include <iostream>
#include <cassert>
#include <limits>

using namespace std;

// Function Prototypes
double sumOfRange(const double arr[], int startIndex, int endIndex, int maxSize);
double productOfRange(const double arr[], int startIndex, int endIndex, int maxSize);
bool allPositive(const double arr[], int maxSize);

/**
 * @brief Calculates the sum of elements in a specified range of an array.
 * @param arr The array of elements.
 * @param startIndex The starting index of the range.
 * @param endIndex The ending index of the range.
 * @param maxSize The maximum size of the array.
 * @return The sum of the elements in the specified range.
 * @note Assumes that startIndex and endIndex are within the bounds of the array.
 */
double sumOfRange(const double arr[], int startIndex, int endIndex, int maxSize) {
    assert(startIndex >= 0 && startIndex < maxSize);
    assert(endIndex >= 0 && endIndex < maxSize);
    assert(startIndex <= endIndex);

    double sum = 0.0;
    for (int i = startIndex; i <= endIndex; ++i) {
        sum += arr[i];
    }
    return sum;
}

/**
 * @brief Calculates the product of elements in a specified range of an array.
 * @param arr The array of elements.
 * @param startIndex The starting index of the range.
 * @param endIndex The ending index of the range.
 * @param maxSize The maximum size of the array.
 * @return The product of the elements in the specified range.
 * @note Assumes that startIndex and endIndex are within the bounds of the array.
 */
double productOfRange(const double arr[], int startIndex, int endIndex, int maxSize) {
    assert(startIndex >= 0 && startIndex < maxSize);
    assert(endIndex >= 0 && endIndex < maxSize);
    assert(startIndex <= endIndex);

    double product = 1.0;
    for (int i = startIndex; i <= endIndex; ++i) {
        product *= arr[i];
    }
    return product;
}

/**
 * @brief Checks if all elements in the array are positive.
 * @param arr The array of elements.
 * @param maxSize The maximum size of the array.
 * @return True if all elements are positive, false otherwise.
 */
bool allPositive(const double arr[], int maxSize) {
    for (int i = 0; i < maxSize; ++i) {
        if (arr[i] <= 0) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Displays the menu and gets the user's choice.
 * @return The user's menu choice.
 */
int displayMenu() {
    cout << "Menu:\n";
    cout << "1. Calculate sum of a range\n";
    cout << "2. Calculate product of a range\n";
    cout << "3. Check if all elements are positive\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    return choice;
}

/**
 * @brief Validates the user's index input.
 * @param prompt The prompt message for the user.
 * @param maxSize The maximum valid index.
 * @return A valid index input by the user.
 */
int getValidIndex(const string& prompt, int maxSize) {
    int index;
    while (true) {
        cout << prompt;
        cin >> index;
        if (cin.fail() || index < 0 || index >= maxSize) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid index between 0 and " << maxSize - 1 << ".\n";
        } else {
            break;
        }
    }
    return index;
}

int main() {
    const int arraySize = 5;
    const double arr[arraySize] = {1.3, 2.2, -3.5, 0.0, 10.2};

    while (true) {
        int choice = displayMenu();

        if (choice == 4) {
            cout << "Exiting...\n";
            break;
        }

        switch (choice) {
            case 1: {
                int startIndex = getValidIndex("Enter start index: ", arraySize);
                int endIndex = getValidIndex("Enter end index: ", arraySize);
                if (startIndex <= endIndex) {
                    double sum = sumOfRange(arr, startIndex, endIndex, arraySize);
                    cout << "Sum of elements from index " << startIndex << " to " << endIndex << " is: " << sum << "\n";
                } else {
                    cout << "Invalid range. Start index should be less than or equal to end index.\n";
                }
                break;
            }
            case 2: {
                int startIndex = getValidIndex("Enter start index: ", arraySize);
                int endIndex = getValidIndex("Enter end index: ", arraySize);
                if (startIndex <= endIndex) {
                    double product = productOfRange(arr, startIndex, endIndex, arraySize);
                    cout << "Product of elements from index " << startIndex << " to " << endIndex << " is: " << product << "\n";
                } else {
                    cout << "Invalid range. Start index should be less than or equal to end index.\n";
                }
                break;
            }
            case 3: {
                bool allPos = allPositive(arr, arraySize);
                if (allPos) {
                    cout << "All elements in the array are positive.\n";
                } else {
                    cout << "Not all elements in the array are positive.\n";
                }
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
