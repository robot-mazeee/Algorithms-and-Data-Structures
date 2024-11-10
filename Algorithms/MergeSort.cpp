#include <iostream>
using std::cout;

void merge(int array[], int const left, int const mid, int const right){
	int const leftSize = mid - left +1;
    int const rightSize = right - mid;

    int *leftArray = new int[leftSize], *rightArray = new int[rightSize];

    for (int i = 0; i < leftSize; i++) leftArray[i] = array[left+i];
    for (int i = 0; i < rightSize; i++) rightArray[i] = array[mid + 1 + i];

    int leftIndex = 0, rightIndex = 0, arrayIndex = left;

    while (leftIndex < leftSize && rightIndex < rightSize){
        if (leftArray[leftIndex] <= rightArray[rightIndex]){
            array[arrayIndex] = leftArray[leftIndex];
            leftIndex ++;
        }

        else{
            array[arrayIndex] = rightArray[rightIndex];
            rightIndex ++;
        }

        arrayIndex++;
    }

    while (leftIndex < leftSize){
        array[arrayIndex] = leftArray[leftIndex];
        leftIndex++;
        arrayIndex++;
    }

    while (rightIndex < rightSize){
        array[arrayIndex] = rightArray[rightIndex];
        rightIndex++;
        arrayIndex++;
    }

    delete[] rightArray;
    delete[] leftArray;
}

void mergeSort(int array[], int const start, int const end){
	if (start >= end) return;

    int mid = start + (end - start) / 2;
    mergeSort(array, start, mid);
    mergeSort(array, mid+1, end);
    merge(array, start, mid, end);
}

int main(){
    int arr[8] = {12, 2, 4, 8, 9, 3, 1, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size-1);

    for (int i = 0; i < size; i++) cout << arr[i] << '\n';

    return 0;
}