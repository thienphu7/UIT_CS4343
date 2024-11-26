//STT: 22521099
//Full name: Le Hoang Thien Phu
// Homework - Ex 3
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <cstdlib>

using namespace std;

struct Student {
    string name;
    int grade;
    int age;
};

// Display students (for verification)
void displayStudents(const vector<Student>& students, int limit = 10) {
    for (int i = 0; i < min(limit, (int)students.size()); ++i) {
        cout << "Name: " << students[i].name
            << ", Grade: " << students[i].grade
            << ", Age: " << students[i].age << endl;
    }
    if (students.size() > limit) {
        cout << "... (" << students.size() - limit << " more students)" << endl;
    }
}

// Generate synthetic student data
vector<Student> generateStudentData(int size) {
    vector<Student> students;
    for (int i = 0; i < size; ++i) {
        students.push_back({
            "Student" + to_string(i),
            rand() % 100 + 1, // Random grade between 1-100
            rand() % 10 + 18  // Random age between 18-27
            });
    }
    return students;
}

// Bubble Sort
void bubbleSort(vector<Student>& students, bool (*compare)(const Student&, const Student&)) {
    for (size_t i = 0; i < students.size() - 1; ++i) {
        for (size_t j = 0; j < students.size() - i - 1; ++j) {
            if (!compare(students[j], students[j + 1])) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

// Quick Sort
void quickSortHelper(vector<Student>& students, int low, int high, bool (*compare)(const Student&, const Student&)) {
    if (low < high) {
        Student pivot = students[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (compare(students[j], pivot)) {
                ++i;
                swap(students[i], students[j]);
            }
        }
        swap(students[i + 1], students[high]);
        int pi = i + 1;
        quickSortHelper(students, low, pi - 1, compare);
        quickSortHelper(students, pi + 1, high, compare);
    }
}

void quickSort(vector<Student>& students, bool (*compare)(const Student&, const Student&)) {
    quickSortHelper(students, 0, students.size() - 1, compare);
}

// Merge Sort
void mergeHelper(vector<Student>& students, int left, int mid, int right, bool (*compare)(const Student&, const Student&)) {
    vector<Student> L(students.begin() + left, students.begin() + mid + 1);
    vector<Student> R(students.begin() + mid + 1, students.begin() + right + 1);
    int i = 0, j = 0, k = left;
    while (i < L.size() && j < R.size()) {
        if (compare(L[i], R[j])) {
            students[k++] = L[i++];
        }
        else {
            students[k++] = R[j++];
        }
    }
    while (i < L.size()) students[k++] = L[i++];
    while (j < R.size()) students[k++] = R[j++];
}

void mergeSortHelper(vector<Student>& students, int left, int right, bool (*compare)(const Student&, const Student&)) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(students, left, mid, compare);
        mergeSortHelper(students, mid + 1, right, compare);
        mergeHelper(students, left, mid, right, compare);
    }
}

void mergeSort(vector<Student>& students, bool (*compare)(const Student&, const Student&)) {
    mergeSortHelper(students, 0, students.size() - 1, compare);
}

// Comparators
bool compareByName(const Student& a, const Student& b) { return a.name < b.name; }
bool compareByGrade(const Student& a, const Student& b) { return a.grade > b.grade; }
bool compareByAge(const Student& a, const Student& b) { return a.age < b.age; }

// Benchmark Function
void benchmark(void (*sortFunc)(vector<Student>&, bool (*compare)(const Student&, const Student&)), vector<Student>& students, const string& sortName, bool (*compare)(const Student&, const Student&)) {
    vector<Student> temp = students;
    auto start = chrono::high_resolution_clock::now();
    sortFunc(temp, compare);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << sortName << " took " << duration.count() << " seconds" << endl;
}

int main() {
    const int DATASET_SIZE = 500; // Large dataset size
    vector<Student> students = generateStudentData(DATASET_SIZE);

    cout << "Generated " << DATASET_SIZE << " students.\n";
    cout << "\nSample students (first 10):\n";
    displayStudents(students);

    cout << "\nSorting by Name:\n";
    benchmark(bubbleSort, students, "Bubble Sort (Name)", compareByName);
    benchmark(quickSort, students, "Quick Sort (Name)", compareByName);
    benchmark(mergeSort, students, "Merge Sort (Name)", compareByName);

    cout << "\nSorting by Grade:\n";
    benchmark(bubbleSort, students, "Bubble Sort (Grade)", compareByGrade);
    benchmark(quickSort, students, "Quick Sort (Grade)", compareByGrade);
    benchmark(mergeSort, students, "Merge Sort (Grade)", compareByGrade);

    cout << "\nSorting by Age:\n";
    benchmark(bubbleSort, students, "Bubble Sort (Age)", compareByAge);
    benchmark(quickSort, students, "Quick Sort (Age)", compareByAge);
    benchmark(mergeSort, students, "Merge Sort (Age)", compareByAge);

    return 0;
}
