//STT: 22521099
//Full name: Le Hoang Thien Phu
// Homework - Ex 5
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>

using namespace std;

// Counting Sort
void countingSort(vector<int>& arr, int maxValue) {
    vector<int> count(maxValue + 1, 0);
    vector<int> output(arr.size());

    for (int num : arr) {
        count[num]++;
    }

    for (size_t i = 1; i < count.size(); ++i) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    arr = output;
}

// Radix Sort
void countingSortForRadix(vector<int>& arr, int exp) {
    vector<int> output(arr.size());
    vector<int> count(10, 0);

    for (int num : arr) {
        count[(num / exp) % 10]++;
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    arr = output;
}

void radixSort(vector<int>& arr) {
    int maxValue = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxValue / exp > 0; exp *= 10) {
        countingSortForRadix(arr, exp);
    }
}

// Benchmark Function
void benchmark(void (*sortFunc)(vector<int>&), vector<int>& arr, const string& sortName) {
    vector<int> temp = arr;
    auto start = chrono::high_resolution_clock::now();
    sortFunc(temp);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << sortName << " took " << duration.count() << " seconds" << endl;
}

// Helper for Counting Sort Benchmark
void countingSortBenchmark(vector<int>& arr, int maxValue, const string& sortName) {
    vector<int> temp = arr;
    auto start = chrono::high_resolution_clock::now();
    countingSort(temp, maxValue);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << sortName << " took " << duration.count() << " seconds" << endl;
}

int main() {
    const int DATASET_SIZE = 100000; // Large dataset size
    vector<int> arr(DATASET_SIZE);

    // Generate random integers
    for (int i = 0; i < DATASET_SIZE; ++i) {
        arr[i] = rand() % 100000;
    }

    cout << "Generated " << DATASET_SIZE << " integers.\n";

    countingSortBenchmark(arr, *max_element(arr.begin(), arr.end()), "Counting Sort");
    benchmark(radixSort, arr, "Radix Sort");

    return 0;
}
