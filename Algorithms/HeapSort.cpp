#include <iostream>
using std::cout;

void heapify(int a[], int heap_size, int i) {
    int largest = i, temp;
    int left = i*2 + 1, right = i*2 +2;

    if (left <= heap_size-1 && a[largest] < a[left]) largest = left;
    if (right <= heap_size-1 && a[largest] < a[right]) largest = right;
    if (largest != i) {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, heap_size, largest);
    }
}

void build_heap(int a[], int heap_size) {
    for (int i = heap_size/2-1; i > -1; i--) {
        heapify(a, heap_size, i);
    }
}

void heap_sort(int a[], int heap_size) {
    int temp;
    build_heap(a, heap_size);

    for (int i = heap_size-1; i > -1; i--) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

int main() {
    int a[] = {2, 16, 12, 11, 15, 7, 6, 10, 20};
    int heap_size = 9;

    heap_sort(a, heap_size);

    for (int elem : a) cout << elem << '\n';

    return 0;
}