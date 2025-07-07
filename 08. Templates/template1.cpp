#include<iostream>
using namespace std;

template<class T>
void calculateAverage()
{
    int size;
    T *ptr;
    T arr[50];
    ptr = arr;

    cout << "Enter the size of array: ";
    cin >> size;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> ptr[i];
    }

    T sum = 0;
    T avg = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    avg = sum / static_cast<T>(size);

    cout << "Average: " << avg;
}

int main() {
    calculateAverage<float>();

    return 0;
}
