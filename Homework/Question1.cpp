#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>
using namespace std;

// Function to display the state of the towers
void displayTowers(vector<stack<int>>& towers, int n) {
    for (int i = 0; i < 3; i++) {
        cout << (char)('A' + i) << " Tower" << endl;
        cout << "STACK = < ";
        stack<int> temp = towers[i];
        vector<int> elements;
        while (!temp.empty()) {
            elements.push_back(temp.top());
            temp.pop();
        }
        for (int j = elements.size() - 1; j >= 0; j--) {
            cout << elements[j] << " ";
        }
        cout << ">" << endl;
        cout << "=========================" << endl;
    }
}

// Function to print the moves
void printMoves(const vector<pair<int, int>>& moves) {
    for (int i = 0; i < moves.size(); i++) {
        cout << i + 1 << ". " << (char)(moves[i].first + 'A') << " -> "
            << (char)(moves[i].second + 'A') << endl;
    }
}

// Recursive function to solve Tower of Hanoi and record moves
void moveDisks(int n, int from, int to, int aux, vector<stack<int>>& towers, vector<pair<int, int>>& moves) {
    if (n == 1) {
        // Move disk from 'from' tower to 'to' tower
        towers[to].push(towers[from].top());
        towers[from].pop();
        moves.push_back({ from, to });
        displayTowers(towers, n);
        return;
    }

    // Move n-1 disks from 'from' tower to 'aux' tower
    moveDisks(n - 1, from, aux, to, towers, moves);

    // Move nth disk from 'from' tower to 'to' tower
    towers[to].push(towers[from].top());
    towers[from].pop();
    moves.push_back({ from, to });
    displayTowers(towers, n);

    // Move n-1 disks from 'aux' tower to 'to' tower
    moveDisks(n - 1, aux, to, from, towers, moves);
}

int main() {
    int n; // Number of disks
    cout << "Enter number of disks: ";
    cin >> n;

    vector<stack<int>> towers(3); // Three towers A, B, and C
    vector<pair<int, int>> moves; // To record the moves

    // Initialize the first tower with disks in descending order
    for (int i = n; i >= 1; i--) {
        towers[0].push(i);
    }

    // Initial display
    cout << "========= Demo Stack =========" << endl;
    cout << "0. Creating Tower." << endl;
    displayTowers(towers, n);

    // Solve the Tower of Hanoi
    moveDisks(n, 0, 2, 1, towers, moves);

    // Display all moves after the process
    cout << "List of moves:" << endl;
    printMoves(moves);

    cout << "========= Finished =========" << endl;

    return 0;
}
