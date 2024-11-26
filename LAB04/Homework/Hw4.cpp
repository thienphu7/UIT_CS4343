//STT: 22521099
//Full name: Le Hoang Thien Phu
// Homework - Ex 4
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <cstdlib>

using namespace std;

struct Song {
    string title;
    string genre;
    string artist;
    string mood;
};

// Display songs
void displaySongs(const vector<Song>& songs, int limit = 10) {
    for (int i = 0; i < min(limit, (int)songs.size()); ++i) {
        cout << "Title: " << songs[i].title
            << ", Genre: " << songs[i].genre
            << ", Artist: " << songs[i].artist
            << ", Mood: " << songs[i].mood << endl;
    }
    if (songs.size() > limit) {
        cout << "... (" << songs.size() - limit << " more songs)" << endl;
    }
}

// Generate synthetic song data
vector<Song> generateSongData(int size) {
    vector<Song> songs;
    string genres[] = { "Pop", "Rock", "Jazz", "Classical", "Hip-Hop" };
    string moods[] = { "Happy", "Sad", "Energetic", "Calm" };
    for (int i = 0; i < size; ++i) {
        songs.push_back({
            "Song" + to_string(i),
            genres[rand() % 5],  // Random genre
            "Artist" + to_string(rand() % 100), // Random artist
            moods[rand() % 4]  // Random mood
            });
    }
    return songs;
}

// Bubble Sort
void bubbleSort(vector<Song>& songs, bool (*compare)(const Song&, const Song&)) {
    for (size_t i = 0; i < songs.size() - 1; ++i) {
        for (size_t j = 0; j < songs.size() - i - 1; ++j) {
            if (!compare(songs[j], songs[j + 1])) {
                swap(songs[j], songs[j + 1]);
            }
        }
    }
}

// Quick Sort
void quickSortHelper(vector<Song>& songs, int low, int high, bool (*compare)(const Song&, const Song&)) {
    if (low < high) {
        Song pivot = songs[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (compare(songs[j], pivot)) {
                ++i;
                swap(songs[i], songs[j]);
            }
        }
        swap(songs[i + 1], songs[high]);
        int pi = i + 1;
        quickSortHelper(songs, low, pi - 1, compare);
        quickSortHelper(songs, pi + 1, high, compare);
    }
}

void quickSort(vector<Song>& songs, bool (*compare)(const Song&, const Song&)) {
    quickSortHelper(songs, 0, songs.size() - 1, compare);
}

// Merge Sort
void mergeHelper(vector<Song>& songs, int left, int mid, int right, bool (*compare)(const Song&, const Song&)) {
    vector<Song> L(songs.begin() + left, songs.begin() + mid + 1);
    vector<Song> R(songs.begin() + mid + 1, songs.begin() + right + 1);
    int i = 0, j = 0, k = left;
    while (i < L.size() && j < R.size()) {
        if (compare(L[i], R[j])) {
            songs[k++] = L[i++];
        }
        else {
            songs[k++] = R[j++];
        }
    }
    while (i < L.size()) songs[k++] = L[i++];
    while (j < R.size()) songs[k++] = R[j++];
}

void mergeSortHelper(vector<Song>& songs, int left, int right, bool (*compare)(const Song&, const Song&)) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(songs, left, mid, compare);
        mergeSortHelper(songs, mid + 1, right, compare);
        mergeHelper(songs, left, mid, right, compare);
    }
}

void mergeSort(vector<Song>& songs, bool (*compare)(const Song&, const Song&)) {
    mergeSortHelper(songs, 0, songs.size() - 1, compare);
}

// Comparators
bool compareByGenre(const Song& a, const Song& b) { return a.genre < b.genre; }
bool compareByArtist(const Song& a, const Song& b) { return a.artist < b.artist; }
bool compareByMood(const Song& a, const Song& b) { return a.mood < b.mood; }

// Benchmark Function
void benchmark(void (*sortFunc)(vector<Song>&, bool (*compare)(const Song&, const Song&)), vector<Song>& songs, const string& sortName, bool (*compare)(const Song&, const Song&)) {
    vector<Song> temp = songs;
    auto start = chrono::high_resolution_clock::now();
    sortFunc(temp, compare);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << sortName << " took " << duration.count() << " seconds" << endl;
}

int main() {
    const int DATASET_SIZE = 500; // Large dataset size
    vector<Song> songs = generateSongData(DATASET_SIZE);

    cout << "Generated " << DATASET_SIZE << " songs.\n";
    cout << "\nSample songs (first 10):\n";
    displaySongs(songs);

    cout << "\nSorting by Genre:\n";
    benchmark(bubbleSort, songs, "Bubble Sort (Genre)", compareByGenre);
    benchmark(quickSort, songs, "Quick Sort (Genre)", compareByGenre);
    benchmark(mergeSort, songs, "Merge Sort (Genre)", compareByGenre);

    cout << "\nSorting by Artist:\n";
    benchmark(bubbleSort, songs, "Bubble Sort (Artist)", compareByArtist);
    benchmark(quickSort, songs, "Quick Sort (Artist)", compareByArtist);
    benchmark(mergeSort, songs, "Merge Sort (Artist)", compareByArtist);

    cout << "\nSorting by Mood:\n";
    benchmark(bubbleSort, songs, "Bubble Sort (Mood)", compareByMood);
    benchmark(quickSort, songs, "Quick Sort (Mood)", compareByMood);
    benchmark(mergeSort, songs, "Merge Sort (Mood)", compareByMood);

    return 0;
}
