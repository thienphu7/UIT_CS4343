// STT: 22521099
// Full Name: Le Hoang Thien Phu
// Lab 04 - Exercise 5
//Notes or Remarks: ......
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <algorithm>

using namespace std;

// Standard Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Binary Search to find the insertion position
int binarySearch(int arr[], int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == item)
            return mid + 1; // Insert after duplicate
        else if (arr[mid] < item)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low; // Position where item should be inserted
}

// Enhanced Insertion Sort using Binary Search
void binaryInsertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int pos = binarySearch(arr, key, 0, i - 1);

        // Shift elements to make room for key
        int j = i - 1;
        while (j >= pos) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[pos] = key;
    }
}

// Function to display an array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Benchmark function to measure sorting performance
template <typename Func>
void benchmark(Func sortFunc, int arr[], int size, const string& sortName) {
    int* tempArr = new int[size];
    copy(arr, arr + size, tempArr);

    auto start = chrono::high_resolution_clock::now();
    sortFunc(tempArr, size);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;
    cout << sortName << " time: " << duration.count() << " seconds" << endl;

    delete[] tempArr;
}

int main() {
    const int size = 1000;
    int arr[size];

    // Populate the array with random numbers
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10000;
    }

    // Display unsorted array (optional, useful for debugging)
    cout << "Unsorted array: ";
    displayArray(arr, 10); // Display first 10 elements for brevity

    // Benchmark Standard Insertion Sort
    benchmark(insertionSort, arr, size, "Standard Insertion Sort");

    // Benchmark Binary Insertion Sort
    benchmark(binaryInsertionSort, arr, size, "Binary Insertion Sort");

    return 0;
}


