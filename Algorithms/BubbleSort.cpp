#include <iostream>
using std::cout;

void bubbleSort(int arr[], int size) {
    int temp;
    bool done = false;

    for (int i = 0; i < size; i++) {
        done = true;
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                done = false;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if (done) break;
    }
}

int main() {
    int arr[] = {8, 9, 2, 10, 4, 5};
    bubbleSort(arr, 6);

    for (int i = 0; i < 6; i++) cout << arr[i] << '\n';

    return 0;
}