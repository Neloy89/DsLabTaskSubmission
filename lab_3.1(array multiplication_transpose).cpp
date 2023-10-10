#include <iostream>
using namespace std;

int main() {
    int a[5][5], b[5][6], c[5][6], trans[6][5];

    cout << "Enter the elements of 1st Array: " << endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }
    cout << "Enter the elements of 2nd Array: " << endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> b[i][j];
        }
    }
    cout << "Array after Multiplication: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            cout << "\t" << c[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            trans[i][j] = c[j][i];
        }
    }
    cout << "Transpose Matrix:" << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "\t" << trans[i][j];
        }
        cout << endl;
    }

    return 0;
}
