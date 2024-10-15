#include <iostream>
#include <vector>

using namespace std;

// Function to calculate how many people each person can see to their right
vector<int> peopleVisibleToRight(const vector<int>& heights) {
    int n = heights.size();
    vector<int> answer(n, 0);  // Result array to store how many people each person can see

    // Loop through each person from left to right
    for (int i = 0; i < n; ++i) {
        int visible_count = 0;

        // Check each person to the right of the current person
        for (int j = i + 1; j < n; ++j) {
            if (heights[j] > heights[i]) {
                visible_count++;  // Can see the taller person, and stop further checking
                break;
            }
            visible_count++;  // Can see this person
        }

        answer[i] = visible_count;
    }

    return answer;
}

int main() {
    int n;

    // Input the number of people and their heights
    cout << "Enter the number of people: ";
    cin >> n;

    vector<int> heights(n);

    // Input the heights from the keyboard
    cout << "Enter the heights: ";
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    // Calculate the answer
    vector<int> result = peopleVisibleToRight(heights);

    // Output the result
    cout << "The number of people each person can see to their right: ";
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    // Explanation
    cout << "Explanation:" << endl;
    for (int i = 0; i < n; ++i) {
        if (result[i] > 0) {
            cout << "Person " << i << " can see ";
            int count = result[i];
            int seenCount = 0;
            // Loop to explain which specific persons can be seen
            for (int j = i + 1; j < n; ++j) {
                seenCount++;
                cout << "person " << j;
                if (seenCount < count) {
                    cout << ", ";
                }
                else {
                    cout << ". ";
                }
                // If a taller person is found, break the loop
                if (heights[j] > heights[i]) {
                    break;
                }
            }
            cout << "so there are " << result[i] << " people in total." << endl;
        }
        else {
            cout << "Person " << i << " can see no one since nobody is to the right of he/she." << endl;
        }
    }

    return 0;
}
