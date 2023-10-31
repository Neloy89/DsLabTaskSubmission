#include<iostream>
using namespace std;

int main()
{
    int minDiff = 50000;
    int num1, num2;
    int arr[10];

    for (int i = 0; i < 10; i++) {
        cout << "Arr[" << i << "] = ";
        cin >> arr[i];
    }

    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            int sum = arr[i] + arr[j];
            if (sum < minDiff) {
                minDiff = sum;
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    cout << "The sum of " << num1 << " and " << num2 << " is closest to zero." << endl;

    return 0;
}
