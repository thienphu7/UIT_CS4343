//STT: 22521099
//Full name: Le Hoang Thien Phu
// Homework - Ex 2
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <cstdlib>

using namespace std;

struct Post {
    string content;
    int likes;
    int shares;
    int comments;
};

// Display posts (for verification)
void displayPosts(const vector<Post>& posts, int limit = 10) {
    for (int i = 0; i < min(limit, (int)posts.size()); ++i) {
        cout << "Post: " << posts[i].content
            << ", Likes: " << posts[i].likes
            << ", Shares: " << posts[i].shares
            << ", Comments: " << posts[i].comments << endl;
    }
    if (posts.size() > limit) {
        cout << "... (" << posts.size() - limit << " more posts)" << endl;
    }
}

// Generate synthetic social media post data
vector<Post> generatePostData(int size) {
    vector<Post> posts;
    for (int i = 0; i < size; ++i) {
        posts.push_back({
            "Post" + to_string(i),
            rand() % 10000, // Likes
            rand() % 10000, // Shares
            rand() % 1000   // Comments
            });
    }
    return posts;
}

// Bubble Sort
void bubbleSort(vector<Post>& posts, bool (*compare)(const Post&, const Post&)) {
    for (size_t i = 0; i < posts.size() - 1; ++i) {
        for (size_t j = 0; j < posts.size() - i - 1; ++j) {
            if (!compare(posts[j], posts[j + 1])) {
                swap(posts[j], posts[j + 1]);
            }
        }
    }
}

// Quick Sort
void quickSortHelper(vector<Post>& posts, int low, int high, bool (*compare)(const Post&, const Post&)) {
    if (low < high) {
        Post pivot = posts[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (compare(posts[j], pivot)) {
                ++i;
                swap(posts[i], posts[j]);
            }
        }
        swap(posts[i + 1], posts[high]);
        int pi = i + 1;
        quickSortHelper(posts, low, pi - 1, compare);
        quickSortHelper(posts, pi + 1, high, compare);
    }
}

void quickSort(vector<Post>& posts, bool (*compare)(const Post&, const Post&)) {
    quickSortHelper(posts, 0, posts.size() - 1, compare);
}

// Merge Sort
void mergeHelper(vector<Post>& posts, int left, int mid, int right, bool (*compare)(const Post&, const Post&)) {
    vector<Post> L(posts.begin() + left, posts.begin() + mid + 1);
    vector<Post> R(posts.begin() + mid + 1, posts.begin() + right + 1);
    int i = 0, j = 0, k = left;
    while (i < L.size() && j < R.size()) {
        if (compare(L[i], R[j])) {
            posts[k++] = L[i++];
        }
        else {
            posts[k++] = R[j++];
        }
    }
    while (i < L.size()) posts[k++] = L[i++];
    while (j < R.size()) posts[k++] = R[j++];
}

void mergeSortHelper(vector<Post>& posts, int left, int right, bool (*compare)(const Post&, const Post&)) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(posts, left, mid, compare);
        mergeSortHelper(posts, mid + 1, right, compare);
        mergeHelper(posts, left, mid, right, compare);
    }
}

void mergeSort(vector<Post>& posts, bool (*compare)(const Post&, const Post&)) {
    mergeSortHelper(posts, 0, posts.size() - 1, compare);
}

// Comparators
bool compareByLikes(const Post& a, const Post& b) { return a.likes > b.likes; }
bool compareByShares(const Post& a, const Post& b) { return a.shares > b.shares; }
bool compareByComments(const Post& a, const Post& b) { return a.comments > b.comments; }

// Benchmark Function
void benchmark(void (*sortFunc)(vector<Post>&, bool (*compare)(const Post&, const Post&)), vector<Post>& posts, const string& sortName, bool (*compare)(const Post&, const Post&)) {
    vector<Post> temp = posts;
    auto start = chrono::high_resolution_clock::now();
    sortFunc(temp, compare);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << sortName << " took " << duration.count() << " seconds" << endl;
}

int main() {
    const int DATASET_SIZE = 2000; // Large dataset size
    vector<Post> posts = generatePostData(DATASET_SIZE);

    cout << "Generated " << DATASET_SIZE << " posts.\n";
    cout << "\nSample posts (first 10):\n";
    displayPosts(posts);

    cout << "\nSorting by Likes:\n";
    benchmark(bubbleSort, posts, "Bubble Sort (Likes)", compareByLikes);
    benchmark(quickSort, posts, "Quick Sort (Likes)", compareByLikes);
    benchmark(mergeSort, posts, "Merge Sort (Likes)", compareByLikes);

    cout << "\nSorting by Shares:\n";
    benchmark(bubbleSort, posts, "Bubble Sort (Shares)", compareByShares);
    benchmark(quickSort, posts, "Quick Sort (Shares)", compareByShares);
    benchmark(mergeSort, posts, "Merge Sort (Shares)", compareByShares);

    cout << "\nSorting by Comments:\n";
    benchmark(bubbleSort, posts, "Bubble Sort (Comments)", compareByComments);
    benchmark(quickSort, posts, "Quick Sort (Comments)", compareByComments);
    benchmark(mergeSort, posts, "Merge Sort (Comments)", compareByComments);

    return 0;
}
