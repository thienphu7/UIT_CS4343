// STT: 22521099
// Full Name: Le Hoang Thien Phu
// Lab 04 - Exercise 1
//Notes or Remarks: ......
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

using namespace std;

// Bubble Sort for integers
void bubbleSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort for integers
void selectionSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort for integers
void insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Quick Sort for integers
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Helper function for benchmarking sorting functions
template <typename SortFunc>
void benchmark(SortFunc sortFunc, const vector<int>& arr, const string& sortName) {
    vector<int> tempArr = arr;  // Make a copy of the array to sort
    auto start = chrono::high_resolution_clock::now();
    sortFunc(tempArr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << sortName << " time: " << duration.count() << " seconds" << endl;
}

int main() {
    const int size = 1000;
    vector<int> arr(size);
    srand(static_cast<unsigned int>(time(0)));

    // Generate 1,000 random integers between 0 and 9999
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10000;
    }

    cout << "Sorting 1000 integers with different algorithms:" << endl;

    // Benchmark each sorting algorithm
    benchmark(bubbleSort, arr, "Bubble Sort");
    benchmark(selectionSort, arr, "Selection Sort");
    benchmark(insertionSort, arr, "Insertion Sort");

    // Quick Sort requires different parameters
    auto start = chrono::high_resolution_clock::now();
    vector<int> tempArr = arr;
    quickSort(tempArr, 0, size - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> quickSortDuration = end - start;
    cout << "Quick Sort time: " << quickSortDuration.count() << " seconds" << endl;

    return 0;
}
