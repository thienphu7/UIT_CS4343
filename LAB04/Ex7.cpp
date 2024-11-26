// STT: 22521099
// Full Name: Le Hoang Thien Phu
// Lab 04 - Exercise 7
//Notes or Remarks: ......
#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector> // For dynamic arrays using std::vector

using namespace std;

// Insertion Sort
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

// Standard Merge Function for Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary vectors
    vector<int> L(n1), R(n2);

    // Copy data to temporary vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary vectors back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Hybrid Merge-Insertion Sort
void hybridMergeSort(int arr[], int left, int right) {
    // Use Insertion Sort if the array size is <= 10
    if (right - left + 1 <= 10) {
        insertionSort(arr, left, right);
    }
    else {
        int mid = left + (right - left) / 2;
        hybridMergeSort(arr, left, mid);
        hybridMergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Standard Merge Sort for comparison
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
    int* tempArr = new int[size];
    copy(arr, arr + size, tempArr);

    auto start = chrono::high_resolution_clock::now();
    sortFunc(tempArr, 0, size - 1);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;
    cout << sortName << " time: " << duration.count() << " seconds" << endl;

    delete[] tempArr;
}

int main() {
    const int size = 1000;
    int arr[size];

    // Populate the array with random numbers
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10000;
    }

    // Display unsorted array (optional)
    cout << "Unsorted array (first 150 elements): ";
    displayArray(arr, 150); // Display first 150 elements for brevity
    cout << endl;

    // Benchmark Standard Merge Sort
    benchmark(mergeSort, arr, size, "Standard Merge Sort");

    // Benchmark Hybrid Merge-Insertion Sort
    benchmark(hybridMergeSort, arr, size, "Hybrid Merge-Insertion Sort");

    return 0;
}
