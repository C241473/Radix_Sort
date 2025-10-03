#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSortByDigit(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int base = 10;
    vector<int> count(base, 0);

    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % base;
        count[digit]++;
    }
    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % base;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    if (arr.empty()) return;
    int maxv = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxv / exp > 0; exp *= 10) {
        countingSortByDigit(arr, exp);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nBefore sorting:\n";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";

    radixSort(arr);

    cout << "\nAfter sorting:\n";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
