#include <iostream>
using std::cout;

int partition(int a[], int left, int right) {
    int i = left-1;
    int j = right;
    int pivot = a[right];
    int temp;

    while (i < j) {
        while (a[++i] < pivot);
        while (pivot < a[--j]) {
            if (j == left) break;
        }
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i];
    a[i] = a[right];
    a[right] = temp;

    return i;
}

void quickSort(int a[], int left, int right) {
    if (right <= left) return;

    int pivot = partition(a, left, right);
    quickSort(a, left, pivot-1);
    quickSort(a, pivot+1, right);
}

int main() {
    int arr[] = {3, 12, 7, 9, 14, 6, 13, 8};
    int size = 8;

    quickSort(arr, 0, size-1);

    for (int i = 0; i < size; i++) cout << arr[i] << ' ';

    return 0;
}
