#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <thread>
#include <future>
#include <chrono>
#include <queue>
#include <mutex>
#include <unordered_map>
#include <cstring>

using namespace std;

// Function prototypes for each exercise and homework question
void exercise1();
void exercise2();
void exercise3();
void exercise4();
void exercise5();
void exercise6();
void exercise7();
void homework1();
void homework2();
void homework3();
void homework4();
void homework5();
void homework6();

void displayMenu()
{
    cout << "\n----------------------------- Menu -----------------------------\n";
    cout << "Exercises:\n";
    for (int i = 1; i <= 7; i++) cout << "  " << i << ". Exercise " << i << endl;
    cout << "\nHomework:\n";
    for (int i = 1; i <= 6; i++) cout << "  " << i << ". Homework " << i << endl;
    cout << "\nEnter 1-7 to solve exercise 1-7, press 8-13 to solve homework 1-6, or 0 to exit: ";
}

// Main function to display menu and handle user's choice
int main()
{
    while (true)
    {
        displayMenu();

        int choice;
        cin >> choice;
        cin.ignore();  // Ignore newline character after the choice input

        switch (choice)
        {
        case 0: return 0;
        case 1: exercise1(); break;
        case 2: exercise2(); break;
        case 3: exercise3(); break;
        case 4: exercise4(); break;
        case 5: exercise5(); break;
        case 6: exercise6(); break;
        case 7: exercise7(); break;
        case 8: homework1(); break;
        case 9: homework2(); break;
        case 10: homework3(); break;
        case 11: homework4(); break;
        case 12: homework5(); break;
        case 13: homework6(); break;
        default: cout << "Invalid choice. Please try again.\n";
        }

        cout << "\nPress Enter to return to the menu...\n";
        cin.ignore();
    }
}

// Exercise 1: Count occurrences of an element using binary search
void exercise1() 
{
    vector<int> arr = { 1, 2, 2, 2, 3, 4, 5 };  // Sample sorted array
    int target = 2;

    // Find the first occurrence of the target
    auto lower = lower_bound(arr.begin(), arr.end(), target);
    // Find the last occurrence of the target
    auto upper = upper_bound(arr.begin(), arr.end(), target);

    int count = upper - lower;  // Number of occurrences

    // Print the array
    cout << "Array: ";
    for (int num : arr) 
    {
        cout << num << " ";
    }

    cout << endl;
    cout << "Count of " << target << " is: " << count << endl;
}

// Exercise 2: Jump search with dynamic step size
void exercise2() 
{
    vector<int> arr = { 1, 3, 5, 7, 9, 11, 13, 15, 17 };  // Sorted array

    // Print the array
    cout << "Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    int target = 7;
    int n = arr.size();
    int step = sqrt(n);  // Initial step size

    int prev = 0;
    while (arr[min(step, n) - 1] < target) 
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n) 
        {
            cout << target << " not found.\n";
            return;
        }
    }

    // Linear search in the found block
    for (int i = prev; i < min(step, n); i++)
    {
        if (arr[i] == target) 
        {
            cout << "Found " << target << " at index " << i << endl;
            return;
        }
    }

    cout << target << " not found.\n";
}

// Exercise 3: Interpolation search for lexicographically sorted strings
void exercise3() 
{
    vector<string> arr = { "apple", "banana", "cherry", "date", "fig", "grape" };

    // Print the array
    cout << "Array: ";
    for (const string& word : arr) {
        cout << word << " ";
    }
    cout << endl;

    string target = "cherry";
    int low = 0, high = arr.size() - 1;

    while (low <= high && target >= arr[low] && target <= arr[high])
    {
        int pos = low + (target.compare(arr[low]) * (high - low)) / (arr[high].compare(arr[low]));

        if (arr[pos] == target) 
        {
            cout << "Found " << target << " at index " << pos << endl;
            return;
        }

        if (arr[pos] < target) low = pos + 1;
        else high = pos - 1;
    }

    cout << target << " not found.\n";
}

// Exercise 4: Find missing number using binary search technique
void exercise4() 
{
    vector<int> arr = { 0, 1, 2, 3, 5 };  // Array with missing number

    // Print the array
    cout << "Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    int left = 0, right = arr.size() - 1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == mid) left = mid + 1;
        else right = mid - 1;
    }

    cout << "Missing number is: " << left << endl;
}

// Exercise 5: Multi-threaded searching system
void exercise5() 
{
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };  // Sample array

    // Print the array
    cout << "Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    int target = 5;

    auto linear_search = [](const vector<int>& arr, int target) {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == target) return i;
        }
        return -1;
        };

    auto binary_search = [](const vector<int>& arr, int target) 
        {
        int left = 0, right = arr.size() - 1;

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
        };

    auto jump_search = [](const vector<int>& arr, int target) 
        {
        int n = arr.size();
        int step = sqrt(n);
        int prev = 0;

        while (arr[min(step, n) - 1] < target) 
        {
            prev = step;
            step += sqrt(n);
            if (prev >= n) return -1;
        }

        for (int i = prev; i < min(step, n); i++) 
        {
            if (arr[i] == target) return i;
        }

        return -1;
        };

    // Run searches concurrently
    auto result1 = async(linear_search, arr, target);
    auto result2 = async(binary_search, arr, target);
    auto result3 = async(jump_search, arr, target);

    cout << "Linear search result: " << result1.get() << endl;
    cout << "Binary search result: " << result2.get() << endl;
    cout << "Jump search result: " << result3.get() << endl;
}

// Exercise 6: Bidirectional binary search
void exercise6() 
{
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };  // Sample sorted array

    // Print the array
    cout << "Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    int target = 5;

    int left = 0, right = arr.size() - 1;

    while (left <= right) 
    {
        if (arr[left] == target) 
        {
            cout << "Found " << target << " at index " << left << endl;
            return;
        }

        if (arr[right] == target) {
            cout << "Found " << target << " at index " << right << endl;
            return;
        }

        left++;
        right--;
    }

    cout << target << " not found.\n";
}

// Exercise 7: Find kth smallest element using modified binary search
void exercise7() 
{
    vector<int> arr = { 7, 10, 4, 3, 20, 15 };

    // Print the array
    cout << "Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    int k = 3;
    nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
    cout << "The " << k << "th smallest element is: " << arr[k - 1] << endl;
}

// Homework 1: K-D Tree for nearest neighbor search
struct KDNode 
{
    vector<int> point;
    KDNode* left;
    KDNode* right;
    KDNode(vector<int> pt) : point(pt), left(nullptr), right(nullptr) {}
};

// Recursive function to build the K-D tree
KDNode* buildKDTree(vector<vector<int>>& points, int depth = 0) 
{
    if (points.empty()) return nullptr;

    // Calculate current dimension
    int k = points[0].size();
    int axis = depth % k;

    // Sort points and find the median
    sort(points.begin(), points.end(), [axis](vector<int>& a, vector<int>& b) {
        return a[axis] < b[axis];
        });
    int median = points.size() / 2;

    // Recursively build tree
    KDNode* node = new KDNode(points[median]);
    vector<vector<int>> leftPoints(points.begin(), points.begin() + median);
    vector<vector<int>> rightPoints(points.begin() + median + 1, points.end());
    node->left = buildKDTree(leftPoints, depth + 1);
    node->right = buildKDTree(rightPoints, depth + 1);
    return node;
}

// Function to find nearest neighbor using K-D Tree
double distance(const vector<int>& a, const vector<int>& b) {
    double dist = 0;
    for (int i = 0; i < a.size(); i++) {
        dist += pow(a[i] - b[i], 2);
    }
    return sqrt(dist);
}

void nearestNeighbor(KDNode* root, const vector<int>& target, int depth, KDNode*& best, double& bestDist) {
    if (!root) return;

    int axis = depth % target.size();
    double d = distance(root->point, target);

    if (d < bestDist) {
        bestDist = d;
        best = root;
    }

    KDNode* nextBranch = (target[axis] < root->point[axis]) ? root->left : root->right;
    KDNode* otherBranch = (target[axis] < root->point[axis]) ? root->right : root->left;

    nearestNeighbor(nextBranch, target, depth + 1, best, bestDist);

    if (abs(root->point[axis] - target[axis]) < bestDist) {
        nearestNeighbor(otherBranch, target, depth + 1, best, bestDist);
    }
}

void homework1() {
    vector<vector<int>> points = { {3, 6}, {17, 15}, {13, 15}, {6, 12}, {9, 1}, {2, 7}, {10, 19} };
    vector<int> target = { 9, 2 };

    // Print the points array
    cout << "Points: ";
    for (const auto& point : points) {
        cout << "(" << point[0] << ", " << point[1] << ") ";
    }
    cout << "\nTarget point: (" << target[0] << ", " << target[1] << ")\n";

    KDNode* root = buildKDTree(points);
    KDNode* best = nullptr;
    double bestDist = INFINITY;

    nearestNeighbor(root, target, 0, best, bestDist);

    cout << "Nearest neighbor is: ";
    for (int coord : best->point) cout << coord << " ";
    cout << "with distance " << bestDist << endl;
}

// Homework 2: Closest pair of points in 2D space using divide and conquer
struct Point {
    int x, y;
};

double dist(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double closestPairRec(vector<Point>& points, int left, int right) {
    if (right - left <= 3) {
        double minDist = INFINITY;
        for (int i = left; i < right; i++) {
            for (int j = i + 1; j < right; j++) {
                minDist = min(minDist, dist(points[i], points[j]));
            }
        }
        return minDist;
    }

    int mid = left + (right - left) / 2;
    double dl = closestPairRec(points, left, mid);
    double dr = closestPairRec(points, mid + 1, right);
    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = left; i < right; i++) {
        if (abs(points[i].x - points[mid].x) < d) strip.push_back(points[i]);
    }

    sort(strip.begin(), strip.end(), [](Point a, Point b) { return a.y < b.y; });

    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; ++j) {
            d = min(d, dist(strip[i], strip[j]));
        }
    }

    return d;
}

void homework2() {
    vector<Point> points = { {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4} };

    // Print the points array
    cout << "Points: ";
    for (const auto& point : points) {
        cout << "(" << point.x << ", " << point.y << ") ";
    }
    cout << endl;

    sort(points.begin(), points.end(), [](Point a, Point b) { return a.x < b.x; });
    double result = closestPairRec(points, 0, points.size());
    cout << "The closest pair distance is: " << result << endl;
}

// Homework 3: Exponential backoff in a distributed system
void exponentialBackoffSearch(int target, vector<int>& data) {
    int retries = 0;
    int index = -1;

    while (retries < 5) {
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == target) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            cout << "Found target at index " << index << endl;
            return;
        }
        retries++;
        int backoffTime = pow(2, retries);  // Exponential backoff
        cout << "Retrying in " << backoffTime << " seconds...\n";
        this_thread::sleep_for(chrono::seconds(backoffTime));
    }
    cout << "Failed to find target after retries.\n";
}

void homework3() {
    vector<int> data = { 1, 2, 3, 4, 5 };
    int target = 4;

    // Print the data array
    cout << "Data: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << "\nTarget: " << target << endl;
    
    exponentialBackoffSearch(target, data);
}

// Homework 4: Multi-threaded K-Nearest Neighbors (KNN) search
void knnThread(const vector<vector<int>>& data, const vector<int>& target, int k, vector<vector<int>>& results, int start, int end) {
    vector<pair<double, vector<int>>> distances;

    for (int i = start; i < end; i++) {
        double d = distance(data[i], target);
        distances.push_back({ d, data[i] });
    }
    sort(distances.begin(), distances.end());
    for (int i = 0; i < k && i < distances.size(); i++) {
        results.push_back(distances[i].second);
    }
}

void homework4() {
    vector<vector<int>> data = { {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6} };
    vector<int> target = { 3, 4 };
    int k = 3;

    // Print the data array
    cout << "Data points: ";
    for (const auto& point : data) {
        cout << "(" << point[0] << ", " << point[1] << ") ";
    }
    cout << "\nTarget point: (" << target[0] << ", " << target[1] << ")\n";
    cout << "K = " << k << endl;

    vector<vector<int>> results;
    int numThreads = 2;
    int chunkSize = data.size() / numThreads;

    vector<thread> threads;
    for (int i = 0; i < numThreads; i++) {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? data.size() : (i + 1) * chunkSize;
        threads.push_back(thread(knnThread, ref(data), ref(target), k, ref(results), start, end));
    }

    for (auto& t : threads) t.join();

    cout << "K-Nearest Neighbors:\n";
    for (const auto& neighbor : results) {
        for (int val : neighbor) cout << val << " ";
        cout << endl;
    }
}

// Homework 5: Real-time data search
void realTimeSearch(vector<int>& data, int target) {
    while (true) {
        auto it = find(data.begin(), data.end(), target);
        if (it != data.end()) {
            cout << "Found target " << target << endl;
            break;
        }
        else {
            cout << "Target not found, updating data...\n";
            data.push_back(target);  // Simulate real-time data update
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
}

void homework5() {
    vector<int> data = { 1, 2, 3, 4, 5 };
    int target = 6;

    // Print the initial data array
    cout << "Initial data: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << "\nTarget to find: " << target << endl;

    thread searchThread(realTimeSearch, ref(data), target);
    searchThread.join();
}

// Homework 6: Pattern matching (KMP algorithm)
void computeLPSArray(const string& pat, vector<int>& lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < pat.size()) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(const string& pat, const string& txt) {
    int M = pat.size();
    int N = txt.size();

    vector<int> lps(M);
    computeLPSArray(pat, lps);

    int i = 0, j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == M) {
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}

void homework6() {
    string txt = "ababcabcabababd";
    string pat = "ababd";

    // Print the text and pattern
    cout << "Text: " << txt << endl;
    cout << "Pattern to search: " << pat << endl;

    KMPSearch(pat, txt);
}