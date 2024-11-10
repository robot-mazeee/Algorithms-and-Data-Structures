#include <iostream>
using std::cout, std::cin;

void selectionSort(int arr[], int size) {
    int i, j;
    int min, temp;

    for (i = 0; i < size; i++) {
        min = i;
        for (j = i+1; j < size; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i <n; i++) cin >> arr[i];

    selectionSort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << '\n';
    
    return 0;
}