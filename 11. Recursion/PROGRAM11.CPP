#include <iostream>
#include <vector>
using namespace std;

void findIndices(const string& str, char target, int index, vector<int>& indices) {
    if (index == str.length()) return;
    if (str[index] == target) indices.push_back(index);
    findIndices(str, target, index + 1, indices);
}

int main() {
    string str;
    char target;
    cout << "Enter string: ";
    getline(cin, str);
    cout << "Enter target character: ";
    cin >> target;

    vector<int> indices;
    findIndices(str, target, 0, indices);

    cout << "Target indices: ";
    for (int idx : indices) cout << idx << " ";
    cout << endl;

    return 0;
}