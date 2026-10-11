#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    int arr[10][10];

    cout << "Enter elements:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];

    cout << "\n2D Array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }

    // Sum of all elements
    int sum = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sum += arr[i][j];
    cout << "\nSum of all elements: " << sum << endl;

    // Transpose
    cout << "\nTranspose:\n";
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
    return 0;
}
