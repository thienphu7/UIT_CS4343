// STT: 22521099
// Full Name: Le Hoang Thien Phu
// Lab 04 - Exercise 6
//Notes or Remarks: ......
#include <iostream>
#include <vector>

using namespace std;

// Function to "heapify" a subtree rooted at index `i`
// `n` is the size of the heap
void heapify(int arr[], int n, int i) {
    int largest = i;            // Assume the root (i) is the largest initially
    int left = 2 * i + 1;       // Left child index
    int right = 2 * i + 2;      // Right child index

    cout << "Heapifying at index " << i << ", left = " << left << ", right = " << right << endl;

    // If left child is larger than the root, update largest
    if (left < n && arr[left] > arr[largest]) {
        cout << "Left child " << arr[left] << " is larger than current largest " << arr[largest] << endl;
        largest = left;
    }

    // If right child is larger than the current largest, update largest
    if (right < n && arr[right] > arr[largest]) {
        cout << "Right child " << arr[right] << " is larger than current largest " << arr[largest] << endl;
        largest = right;
    }

    // If largest is not the root, swap it with the largest element and continue heapifying
    if (largest != i) {
        cout << "Swapping " << arr[i] << " with " << arr[largest] << endl;
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected subtree
    }
}

// Function to build a Max-Heap from an array
void buildMaxHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--) {
        cout << "Building max-heap: heapifying index " << i << endl;
        heapify(arr, n, i);
    }
}

// Function to find the maximum element in an array using Heap Sort
int findMaxUsingHeap(int arr[], int n) {
    // Step 1: Build a Max-Heap from the array
    cout << "\nBuilding the max-heap..." << endl;
    buildMaxHeap(arr, n);
    cout << "Max-heap built successfully." << endl;

    // Step 2: The maximum element is at the root of the Max-Heap
    int maxElement = arr[0];
    cout << "Maximum element found at the root of the heap: " << maxElement << endl;
    return maxElement;
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 3, 9, 2, 1, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);
    cout << endl;

    // Find the maximum element using Heap Sort method
    int maxElement = findMaxUsingHeap(arr, n);

    cout << "\nArray after building max-heap (structure only, not fully sorted): ";
    printArray(arr, n);

    cout << "Maximum element in the array is: " << maxElement << endl;

    return 0;
}


