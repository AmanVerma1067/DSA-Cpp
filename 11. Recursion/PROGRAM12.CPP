#include <iostream>
using namespace std;

// Recursive function to count digits
int countDigits(int n) {
    if (n == 0)
        return 0;
    return 1 + countDigits(n / 10);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    // Handle 0 as a special case
    if (num == 0)
        cout << "Number of digits: 1" << endl;
    else
        cout << "Number of digits: " << countDigits(abs(num)) << endl;
    return 0;
}
