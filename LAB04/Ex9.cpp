// STT: 22521099
// Full Name: Le Hoang Thien Phu
// Lab 04 - Exercise 9
//Notes or Remarks: ......
#include <iostream>
#include <vector>
#include <cmath>     
#include <chrono>     
#include <algorithm>  

using namespace std;

// Structure to represent a point in multi-dimensional space
struct Point {
    vector<double> coordinates; // Dynamic vector to handle any number of dimensions

    // Function to calculate the distance from the origin (0, 0, ..., 0)
    double distanceFromOrigin() const {
        double sum = 0;
        for (double coord : coordinates) {
            sum += coord * coord; // Sum of squares
        }
        return sqrt(sum); // Euclidean distance
    }
};

// Function to display points
void displayPoints(const vector<Point>& points) {
    for (const auto& point : points) {
        cout << "(";
        for (size_t i = 0; i < point.coordinates.size(); ++i) {
            cout << point.coordinates[i];
            if (i < point.coordinates.size() - 1) cout << ", ";
        }
        cout << ") ";
    }
    cout << endl;
}

// Bubble Sort for Points
void bubbleSortPoints(vector<Point>& points) {
    for (size_t i = 0; i < points.size() - 1; ++i) {
        for (size_t j = 0; j < points.size() - i - 1; ++j) {
            if (points[j].distanceFromOrigin() > points[j + 1].distanceFromOrigin()) {
                swap(points[j], points[j + 1]);
            }
        }
    }
}

// Selection Sort for Points
void selectionSortPoints(vector<Point>& points) {
    for (size_t i = 0; i < points.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < points.size(); ++j) {
            if (points[j].distanceFromOrigin() < points[minIndex].distanceFromOrigin()) {
                minIndex = j;
            }
        }
        swap(points[i], points[minIndex]);
    }
}

// Insertion Sort for Points
void insertionSortPoints(vector<Point>& points) {
    for (size_t i = 1; i < points.size(); ++i) {
        Point key = points[i];
        int j = i - 1;
        while (j >= 0 && points[j].distanceFromOrigin() > key.distanceFromOrigin()) {
            points[j + 1] = points[j];
            --j;
        }
        points[j + 1] = key;
    }
}

// Partition function for Quick Sort
int partitionPoints(vector<Point>& points, int low, int high) {
    double pivot = points[high].distanceFromOrigin(); // Pivot is the distance of the last point
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (points[j].distanceFromOrigin() <= pivot) {
            ++i;
            swap(points[i], points[j]);
        }
    }
    swap(points[i + 1], points[high]);
    return i + 1;
}

// Quick Sort for Points
void quickSortPoints(vector<Point>& points, int low, int high) {
    if (low < high) {
        int pi = partitionPoints(points, low, high);
        quickSortPoints(points, low, pi - 1);
        quickSortPoints(points, pi + 1, high);
    }
}

// Benchmark function to measure and display the execution time of a sorting function
template <typename SortFunc>
void benchmark(SortFunc sortFunc, vector<Point> points, const string& sortName) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(points);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;
    cout << sortName << " took " << duration.count() << " seconds" << endl;

    cout << "Sorted points by " << sortName << ": ";
    displayPoints(points);
    cout << endl;
}

int main() {
    int numPoints, numDimensions;

    // Input number of points and dimensions
    cout << "Enter the number of points: ";
    cin >> numPoints;
    cout << "Enter the number of dimensions: ";
    cin >> numDimensions;

    // Input points from the user
    vector<Point> points(numPoints);
    for (int i = 0; i < numPoints; ++i) {
        cout << "Enter coordinates for point " << i + 1 << ": ";
        points[i].coordinates.resize(numDimensions);
        for (int j = 0; j < numDimensions; ++j) {
            cin >> points[i].coordinates[j];
        }
    }

    // Display the original points
    cout << "\nOriginal points:" << endl;
    displayPoints(points);

    // Benchmark Bubble Sort
    benchmark(bubbleSortPoints, points, "Bubble Sort");

    // Benchmark Selection Sort
    benchmark(selectionSortPoints, points, "Selection Sort");

    // Benchmark Insertion Sort
    benchmark(insertionSortPoints, points, "Insertion Sort");

    // Benchmark Quick Sort
    vector<Point> quickSortPointsCopy = points; // Copy for Quick Sort
    auto start = chrono::high_resolution_clock::now();
    quickSortPoints(quickSortPointsCopy, 0, quickSortPointsCopy.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> quickSortDuration = end - start;
    cout << "Quick Sort took " << quickSortDuration.count() << " seconds" << endl;
    cout << "Sorted points by Quick Sort: ";
    displayPoints(quickSortPointsCopy);

    return 0;
}

