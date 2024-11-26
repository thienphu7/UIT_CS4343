// STT: 22521099
// Full Name: Le Hoang Thien Phu
// Lab 04 - Exercise 8
//Notes or Remarks: ......
#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

// Insertion Sort: Used for sorting smaller subarrays
void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Partition Function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1; // Return the partitioning index
}

// Standard Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition the array

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Hybrid Quick-Insertion Sort
void hybridQuickSort(int arr[], int low, int high) {
    const int THRESHOLD = 10; // Switch to Insertion Sort for arrays of size <= 10

    if (low < high) {
        // If the subarray size is less than or equal to the threshold, use Insertion Sort
        if (high - low + 1 <= THRESHOLD) {
            insertionSort(arr, low, high);
        }
        else {
            // Otherwise, use Quick Sort
            int pi = partition(arr, low, high);

            // Recursively sort elements before and after partition
            hybridQuickSort(arr, low, pi - 1);
            hybridQuickSort(arr, pi + 1, high);
        }
    }
}

// Function to display an array (useful for debugging)
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Benchmark function to measure sorting performance
template <typename Func>
void benchmark(Func sortFunc, int arr[], int size, const string& sortName) {
    int* tempArr = new int[size]; // Create a temporary array for the sort
    copy(arr, arr + size, tempArr); // Copy the original array into tempArr

    auto start = chrono::high_resolution_clock::now(); // Start timing
    sortFunc(tempArr, 0, size - 1); // Run the sorting function
    auto end = chrono::high_resolution_clock::now(); // End timing

    chrono::duration<double> duration = end - start; // Calculate the duration
    cout << sortName << " time: " << duration.count() << " seconds" << endl;

    delete[] tempArr; // Clean up memory
}

int main() {
    const int size = 1000; // Size of the array
    int arr[size];

    // Populate the array with random numbers
    srand(static_cast<unsigned int>(time(0))); // Seed for randomness
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10000; // Generate random numbers between 0 and 9999
    }

    // Display the first 10 elements of the unsorted array
    cout << "Unsorted array (first 10 elements): ";
    displayArray(arr, 10);

    // Benchmark Standard Quick Sort
    benchmark(quickSort, arr, size, "Standard Quick Sort");

    // Benchmark Hybrid Quick-Insertion Sort
    benchmark(hybridQuickSort, arr, size, "Hybrid Quick-Insertion Sort");

    return 0;
}



