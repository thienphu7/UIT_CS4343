// STT: 22521099
// Full Name: Le Hoang Thien Phu
// Lab 04 - Exercise 2
//Notes or Remarks: ......
#include <iostream>
#include <chrono>
#include <cstdlib>   // For rand() and srand()
#include <algorithm> // For swap()
#include <vector>
#include <ctime>     // For time()

using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
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

// Quick Sort
int partition(int arr[], int low, int high) {
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

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Benchmark function
void benchmarkSort(void (*sortFunc)(int[], int), int arr[], int size, const string& sortName) {
    int* tempArr = new int[size];
    copy(arr, arr + size, tempArr);

    auto start = chrono::high_resolution_clock::now();
    sortFunc(tempArr, size);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;
    cout << sortName << " time for size " << size << ": " << duration.count() << " seconds" << endl;

    delete[] tempArr;
}

// Benchmark function for quickSort and mergeSort with additional parameters
void benchmarkQuickMerge(void (*sortFunc)(int[], int, int), int arr[], int size, const string& sortName) {
    int* tempArr = new int[size];
    copy(arr, arr + size, tempArr);

    auto start = chrono::high_resolution_clock::now();
    sortFunc(tempArr, 0, size - 1);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;
    cout << sortName << " time for size " << size << ": " << duration.count() << " seconds" << endl;

    delete[] tempArr;
}

int main() {
    const int sizes[] = { 100, 1000, 10000 };
    const int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    for (int i = 0; i < numSizes; ++i) {
        int size = sizes[i];
        int* arr = new int[size];

        // Populate the array with random numbers
        for (int j = 0; j < size; ++j) {
            arr[j] = rand() % 10000;
        }

        // Run benchmarks for each sorting algorithm
        benchmarkSort(bubbleSort, arr, size, "Bubble Sort");
        benchmarkSort(selectionSort, arr, size, "Selection Sort");
        benchmarkSort(insertionSort, arr, size, "Insertion Sort");
        benchmarkQuickMerge(quickSort, arr, size, "Quick Sort");
        benchmarkQuickMerge(mergeSort, arr, size, "Merge Sort");

        delete[] arr;
        cout << "--------------------------------------------------------------------" << endl;
    }

    return 0;
}
