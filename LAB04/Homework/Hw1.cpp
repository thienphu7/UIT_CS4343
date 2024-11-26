//STT: 22521099
//Full name: Le Hoang Thien Phu
// Homework - Ex 1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <cstdlib> // For random data generation
#include <iomanip>

using namespace std;

struct Product {
    string name;
    double price;
    int rating;
    int popularity;
};

// Display a subset of products
void displayProducts(const vector<Product>& products, int limit = 10) {
    for (int i = 0; i < min(limit, (int)products.size()); ++i) {
        cout << fixed << setprecision(2) << "Name: " << products[i].name
            << ", Price: " << products[i].price
            << ", Rating: " << products[i].rating
            << ", Popularity: " << products[i].popularity << endl;
    }
    if (products.size() > limit) {
        cout << "... (" << products.size() - limit << " more products)" << endl;
    }
}

// Generate synthetic product data
vector<Product> generateProductData(int size) {
    vector<Product> products;
    for (int i = 0; i < size; ++i) {
        products.push_back({
            "Product" + to_string(i),
            rand() % 1000 + (rand() % 100) / 100.0, // Random price between 0-999.99
            rand() % 5 + 1,                         // Random rating between 1-5
            rand() % 1000                           // Random popularity score
            });
    }
    return products;
}

// Bubble Sort
void bubbleSort(vector<Product>& products, bool (*compare)(const Product&, const Product&)) {
    for (size_t i = 0; i < products.size() - 1; ++i) {
        for (size_t j = 0; j < products.size() - i - 1; ++j) {
            if (!compare(products[j], products[j + 1])) {
                swap(products[j], products[j + 1]);
            }
        }
    }
}

// Quick Sort
void quickSortHelper(vector<Product>& products, int low, int high, bool (*compare)(const Product&, const Product&)) {
    if (low < high) {
        // Partition the array
        Product pivot = products[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (compare(products[j], pivot)) {
                ++i;
                swap(products[i], products[j]);
            }
        }
        swap(products[i + 1], products[high]);

        int pi = i + 1;

        // Recursive calls
        quickSortHelper(products, low, pi - 1, compare);
        quickSortHelper(products, pi + 1, high, compare);
    }
}

void quickSort(vector<Product>& products, bool (*compare)(const Product&, const Product&)) {
    quickSortHelper(products, 0, products.size() - 1, compare);
}

// Merge Sort
void mergeHelper(vector<Product>& products, int left, int mid, int right, bool (*compare)(const Product&, const Product&)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Product> L(products.begin() + left, products.begin() + mid + 1);
    vector<Product> R(products.begin() + mid + 1, products.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (compare(L[i], R[j])) {
            products[k++] = L[i++];
        }
        else {
            products[k++] = R[j++];
        }
    }

    while (i < n1) products[k++] = L[i++];
    while (j < n2) products[k++] = R[j++];
}

void mergeSortHelper(vector<Product>& products, int left, int right, bool (*compare)(const Product&, const Product&)) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortHelper(products, left, mid, compare);
        mergeSortHelper(products, mid + 1, right, compare);

        mergeHelper(products, left, mid, right, compare);
    }
}

void mergeSort(vector<Product>& products, bool (*compare)(const Product&, const Product&)) {
    mergeSortHelper(products, 0, products.size() - 1, compare);
}

// Comparators
bool compareByPrice(const Product& a, const Product& b) { return a.price < b.price; }
bool compareByRating(const Product& a, const Product& b) { return a.rating > b.rating; }
bool compareByPopularity(const Product& a, const Product& b) { return a.popularity > b.popularity; }

// Benchmark Function
void benchmark(void (*sortFunc)(vector<Product>&, bool (*compare)(const Product&, const Product&)), vector<Product>& products, const string& sortName, bool (*compare)(const Product&, const Product&)) {
    vector<Product> temp = products; // Copy for sorting
    auto start = chrono::high_resolution_clock::now();
    sortFunc(temp, compare);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;
    cout << sortName << " took " << duration.count() << " seconds" << endl;
}

int main() {
    const int DATASET_SIZE = 5000; // Large dataset size
    vector<Product> products = generateProductData(DATASET_SIZE);

    cout << "Generated " << DATASET_SIZE << " products.\n";
    cout << "\nSample products (first 10):\n";
    displayProducts(products);

    cout << "\nSorting by Price:\n";
    benchmark(bubbleSort, products, "Bubble Sort (Price)", compareByPrice);
    benchmark(quickSort, products, "Quick Sort (Price)", compareByPrice);
    benchmark(mergeSort, products, "Merge Sort (Price)", compareByPrice);

    cout << "\nSorting by Rating:\n";
    benchmark(bubbleSort, products, "Bubble Sort (Rating)", compareByRating);
    benchmark(quickSort, products, "Quick Sort (Rating)", compareByRating);
    benchmark(mergeSort, products, "Merge Sort (Rating)", compareByRating);

    cout << "\nSorting by Popularity:\n";
    benchmark(bubbleSort, products, "Bubble Sort (Popularity)", compareByPopularity);
    benchmark(quickSort, products, "Quick Sort (Popularity)", compareByPopularity);
    benchmark(mergeSort, products, "Merge Sort (Popularity)", compareByPopularity);

    return 0;
}






