// STT: 22521099
// Full Name: Le Hoang Thien Phu
// Lab 04 - Exercise 3
//Notes or Remarks: ......
#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Template Bubble Sort
template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Template Selection Sort
template <typename T>
void selectionSort(T arr[], int size) {
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

// Template Insertion Sort
template <typename T>
void insertionSort(T arr[], int size) {
    for (int i = 1; i < size; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Template Quick Sort
template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
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

template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Template Merge Sort
template <typename T>
void merge(vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<T> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

template <typename T>
void mergeSort(vector<T>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to display array
template <typename T>
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to benchmark and test each sorting algorithm
template <typename T>
void testSortingAlgorithms(T arr[], int size) {
    vector<T> tempArr(arr, arr + size);

    // Bubble Sort
    copy(arr, arr + size, tempArr.begin());
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(tempArr.data(), size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> bubble_duration = end - start;
    cout << "Bubble Sort: ";
    displayArray(tempArr.data(), size);
    cout << "Time: " << bubble_duration.count() << " seconds\n";

    // Selection Sort
    copy(arr, arr + size, tempArr.begin());
    start = chrono::high_resolution_clock::now();
    selectionSort(tempArr.data(), size);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> selection_duration = end - start;
    cout << "Selection Sort: ";
    displayArray(tempArr.data(), size);
    cout << "Time: " << selection_duration.count() << " seconds\n";

    // Insertion Sort
    copy(arr, arr + size, tempArr.begin());
    start = chrono::high_resolution_clock::now();
    insertionSort(tempArr.data(), size);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> insertion_duration = end - start;
    cout << "Insertion Sort: ";
    displayArray(tempArr.data(), size);
    cout << "Time: " << insertion_duration.count() << " seconds\n";

    // Quick Sort
    copy(arr, arr + size, tempArr.begin());
    start = chrono::high_resolution_clock::now();
    quickSort(tempArr.data(), 0, size - 1);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> quick_duration = end - start;
    cout << "Quick Sort: ";
    displayArray(tempArr.data(), size);
    cout << "Time: " << quick_duration.count() << " seconds\n";

    // Merge Sort
    copy(arr, arr + size, tempArr.begin());
    start = chrono::high_resolution_clock::now();
    mergeSort(tempArr, 0, size - 1);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> merge_duration = end - start;
    cout << "Merge Sort: ";
    displayArray(tempArr.data(), size);
    cout << "Time: " << merge_duration.count() << " seconds\n";
}

int main() {
    cout << "Default int array: { 5, 3, 8, 6, 2, 7, 4, 1 }\n";
    cout << "Default float array: { 5.5, 3.3, 8.8, 6.6, 2.2, 7.7, 4.4, 1.1 }\n";
    cout << "Default string array: { apple, orange, banana, grape, kiwi, pear }\n";
    cout << endl;

    srand(static_cast<unsigned int>(time(0)));

    cout << endl;
    cout << "Sorting integers:\n";
    int intArr[] = { 5, 3, 8, 6, 2, 7, 4, 1 };
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    testSortingAlgorithms(intArr, intSize);

    cout << "\nSorting floating-point numbers:\n";
    double doubleArr[] = { 5.5, 3.3, 8.8, 6.6, 2.2, 7.7, 4.4, 1.1 };
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    testSortingAlgorithms(doubleArr, doubleSize);

    cout << "\nSorting strings:\n";
    string strArr[] = { "apple", "orange", "banana", "grape", "kiwi", "pear" };
    int strSize = sizeof(strArr) / sizeof(strArr[0]);
    testSortingAlgorithms(strArr, strSize);

    return 0;
}
