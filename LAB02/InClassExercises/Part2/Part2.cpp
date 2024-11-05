#include <iostream>
using namespace std;

const int MAX = 10;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor to initialize.
    Queue() {
        front = rear = NULL;
    }

    // To check if the queue is empty.
    bool isEmpty() {
        return (front == NULL);
    }

    // To check if the queue is full.
    int size() {
        Node* temp = front;
        int cnt = 0;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    bool isFull() {
        return size() >= MAX;
    }

    // To enqueue an element into the queue (add into last).
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (rear == NULL) { // If queue is empty.
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued into the queue.\n";
    }

    // To dequeue an element from the queue (delete First).
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        Node* temp = front;
        front = front->next;

        if (front == NULL) { // If the queue becomes empty.
            rear = NULL;
        }
        cout << "Dequeued element: " << temp->data << endl;
        delete temp;
    }

    // To print the front and rear elements.
    void printFrontAndRear() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        }
        else {
            cout << "Front is: " << front->data << endl;
            cout << "Rear is: " << rear->data << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, value;

    while (1) {
        cout << "----------------- Menu ---------------\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Check if Empty\n";
        cout << "4. Check if Full\n";
        cout << "5. Print Front and Rear\n";
        cout << "6. Exit\n";
        cout << "--------------------------------------\n";
        cout << "Enter your choice: ";

        cin >> choice;
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            if (q.isEmpty()) {
                cout << "Queue is empty.\n";
            }
            else {
                cout << "Queue is not empty.\n";
            }
        }
        else if (choice == 4) {
            if (q.isFull()) {
                cout << "Queue is full.\n";
            }
            else {
                cout << "Queue is not full.\n";
            }
        }
        else if (choice == 5) {
            q.printFrontAndRear();
        }
        else if (choice == 6) {
            cout << "Exiting...\n";
            break; // Exit the loop
        }
        else {
            cout << "Invalid! Please select a valid option (1-6)" << endl;
        }
    }

    return 0;
}
