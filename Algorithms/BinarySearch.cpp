#include <iostream>
using std::cout;

int binary_search(int arr[], int size, int target) {
    int min = 0, max = size-1, mid;

    while (min <= max) {
        mid = (min+max)/2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) min = mid+1;
        else max = mid-1;
    }

    return -1;
}

int main() {
    int arr[7] = {1, 3, 5, 6, 7, 9, 11};

    cout << binary_search(arr, 7, 14);

    return 0;
}