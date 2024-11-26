// STT: 22521099
// Full Name: Le Hoang Thien Phu
// Lab 04 - Exercise 4
//Notes or Remarks: ......
#include <iostream>
#include <chrono>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>


using namespace std;


// Node structure for linked list
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};


// Linked List functions
class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}


    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }


    void bubbleSort() {
        bool swapped;
        Node* ptr;
        Node* lptr = nullptr;
        if (head == nullptr) return;


        do {
            swapped = false;
            ptr = head;
            while (ptr->next != lptr) {
                if (ptr->data > ptr->next->data) {
                    swap(ptr->data, ptr->next->data);
                    swapped = true;
                }
                ptr = ptr->next;
            }
            lptr = ptr;
        } while (swapped);
    }


    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


// Queue-based sorting functions
void bubbleSortQueue(queue<int>& q) {
    int n = q.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            int a = q.front(); q.pop();
            int b = q.front(); q.pop();


            if (a > b) {
                q.push(b);
                q.push(a);
            }
            else {
                q.push(a);
                q.push(b);
            }


            // Move items from front to back to keep original order for next comparison
            for (int k = 0; k < n - 2; ++k) {
                int val = q.front(); q.pop();
                q.push(val);
            }
        }
    }
}


void displayQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}


// Function to bubble sort a stack
void bubbleSortStack(stack<int>& s) {
    int n = s.size();
    for (int i = 0; i < n - 1; ++i) {
        stack<int> temp;
        int previous = s.top();
        s.pop();


        // Bubble the largest element to the top
        for (int j = 0; j < n - i - 1; ++j) {
            int current = s.top();
            s.pop();


            if (previous > current) {
                temp.push(previous);
                previous = current;
            }
            else {
                temp.push(current);
            }
        }


        // Push the largest element to the bottom of the stack
        s.push(previous);


        // Push back all elements from the temporary stack
        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
    }
}


// Function to display the stack
void displayStack(stack<int> s) {
    stack<int> temp;
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}


// Benchmark function to measure sorting performance
template <typename Func>
void benchmark(Func sortFunc, const string& structureName) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << structureName << " sorting time: " << duration.count() << " seconds" << endl;
}


int main() {
    const int dataSize = 10;
    int data[dataSize] = { 4, 1, 3, 9, 7, 8, 5, 6, 2, 0 };


    // Linked List
    LinkedList list;
    for (int i = 0; i < dataSize; ++i) {
        list.insert(data[i]);
    }


    cout << "Linked List before sorting: ";
    list.display();
    benchmark([&]() { list.bubbleSort(); }, "Linked List");
    cout << "Linked List after sorting: ";
    list.display();
    cout << "----------------------------------" << endl;


    // Queue
    queue<int> q;
    for (int i = 0; i < dataSize; ++i) {
        q.push(data[i]);
    }


    cout << "Queue before sorting: ";
    displayQueue(q);
    benchmark([&]() { bubbleSortQueue(q); }, "Queue");
    cout << "Queue after sorting: ";
    displayQueue(q);
    cout << "----------------------------------" << endl;


    // Stack
    stack<int> s;
    for (int i = 0; i < dataSize; ++i) {
        s.push(data[i]);
    }


    cout << "Stack before sorting: ";
    displayStack(s);
    benchmark([&]() { bubbleSortStack(s); }, "Stack");
    cout << "Stack after sorting: ";
    displayStack(s);
    cout << "----------------------------------" << endl;


    return 0;
}
