#include <iostream>
using std::cout;

void insertionSort(int arr[], int size) {
    int i, j;

    for (i = 1; i < size; i++) {
        int current = arr[i];
        j = i - 1;
        while (-1 < j && arr[j] > current) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

int main() {
    int arr[6] = {10, 2, 30, 872, 1, 69};
    insertionSort(arr, 6);
    for (int u : arr) cout << u << '\n';

    return 0;
}