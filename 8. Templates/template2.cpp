#include <iostream>
using namespace std;

// Function template to find the maximum element in an array
template<typename T>
T findMax(T* arr, int size) {
    T max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to display the original array and the maximum element found
template<typename T>
void display(T* arr, int size, T max) {
    cout << "Original Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Maximum Element: " << max << endl;
}

int main() {
    // Example usage
    int intArr[] = {3, 7, 2, 9, 5};
    double doubleArr[] = {3.5, 7.2, 2.9, 9.1, 5.4};

    // Find max for int array
    int intMax = findMax(intArr, 5);
    display(intArr, 5, intMax);

    // Find max for double array
    double doubleMax = findMax(doubleArr, 5);
    display(doubleArr, 5, doubleMax);

    return 0;
}
