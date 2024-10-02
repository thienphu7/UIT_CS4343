/* Write a program to implement a stack using a singly linked list (or an array) to
temporarily store integers (or characters). Perform the following requirements:
 1. Write a function to initialize the stack.
 2. Write a function to check if the stack is empty. If empty, return true, otherwise return false.
 3. Write a function to check if the stack is full (if applicable). If full, return true, otherwise return false.
 4. Write a function to push an element onto the stack.
 5. Write a function to pop an element from the stack.
 6. Print the TOP element of the stack.
 In the main function, write a menu to display the above choices. */
#include <iostream>
using namespace std;

const int MAX = 10;

struct Node {
    int data;
    Node* next;
};

// To initialize a new node.
Node* makeNode(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}

// To check if the stack is empty.
bool empty(Node* a) {
    return a == NULL;
}

// To check if the stack is full.
int size(Node* a) {
    int cnt = 0;
    while (a != NULL) {
        cnt++;
        a = a->next;
    }
    return cnt;
}
bool full(Node* a) {
    return size(a) >= MAX;
}

// To push an element onto the stack.
void push(Node*& a, int x) {
    Node* temp = makeNode(x);
    temp->next = a;
    a = temp;
}

// To pop an element from the stack.
void pop(Node*& a) {
    if (!empty(a)) {
        Node* temp = a;
        a = a->next;
        delete temp;
    }
    else {
        cout << "Stack is empty.\n";
    }
}

// To print the top element of the stack.
void printFirst(Node* a) {
    if (!empty(a)) {
        cout << "Top element is: " << a->data << endl;
    }
    else {
        cout << "Stack is empty.\n";
    }
}

void PrintFullStack(Node* a) {
    while (a != NULL) {
        cout << a->data << " ";
        a = a->next;
    }
    cout << endl;
}

int main() {
    Node* stack = NULL;  // Initialize the stack (empty)
    int choice, value;

    while (1) {
        cout << endl;
        cout << "--------- MENU -------------" << endl;
        cout << "1. Push the element to the first list\n";
        cout << "2. Pop the first element\n";
        cout << "3. Display Top Element\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Check if Stack is Full\n";
        cout << "6. Print the full stack\n";
        cout << "7. Exit\n";
        cout << "----------------------------" << endl;
        cout << "Enter your choice: ";

        cin >> choice;
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            push(stack, value);
        }
        else if (choice == 2) {
            pop(stack);
        }
        else if (choice == 3) {
            printFirst(stack);
        }
        else if (choice == 4) {
            if (empty(stack)) {
                cout << "Stack is empty\n";
            }
            else {
                cout << "Stack is not empty\n";
            }
        }
        else if (choice == 5) {
            if (full(stack)) {
                cout << "Stack is full\n";
            }
            else {
                cout << "Stack is not full\n";
            }
        }
        else if (choice == 6) {
            PrintFullStack(stack);
        }
        else if (choice == 7) {
            cout << "Exiting....\n";
            break;
        }
        else {
            cout << "Invalid! Please select a valid option (1-7)" << endl;
        }
    }

    return 0;
}
