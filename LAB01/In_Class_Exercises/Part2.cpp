#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    Node* next;
}*node;  // Use typedef for node pointer

// Function to create a new node
node makeNode(int x) {
    node temp = new Node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}

// Function to check if the list is empty
bool empty(node a) {
    return a == NULL;
}

// Function to return the size of the list
int size(node a) {
    int cnt = 0;
    while (a != NULL) {
        ++cnt;
        a = a->next;
    }
    return cnt;
}
// Function to print the list
void printList(node head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
// 1. Add two numbers into specific positions of the list
void addTwoNumbers(node& head, int pos1, int pos2, int val1, int val2) {
    node temp = head;
    int idx = 1;

    // Insert the first number at position pos1
    node newNode1 = makeNode(val1);
    if (pos1 == 1) {
        newNode1->next = head;
        head = newNode1;
    }
    else {
        while (temp != NULL && idx < pos1 - 1) {
            temp = temp->next;
            ++idx;
        }
        if (temp != NULL) {
            newNode1->next = temp->next;
            temp->next = newNode1;
        }
    }

    // Insert the second number at position pos2
    idx = 1;
    temp = head;
    node newNode2 = makeNode(val2);
    if (pos2 == 1) {
        newNode2->next = head;
        head = newNode2;
    }
    else {
        while (temp != NULL && idx < pos2 - 1) {
            temp = temp->next;
            ++idx;
        }
        if (temp != NULL) {
            newNode2->next = temp->next;
            temp->next = newNode2;
        }
    }
}

// 2. Copy List with Random Pointers (for simplicity, we copy the list without random pointers)
node copyList(node head) {
    if (!head) return NULL;
    node newHead = makeNode(head->data);
    node newTemp = newHead, temp = head->next;

    while (temp != NULL) {
        newTemp->next = makeNode(temp->data);
        newTemp = newTemp->next;
        temp = temp->next;
    }

    return newHead;
}

// 3. Swap two nodes in a linked list
void swapNodes(node& head, int pos1, int pos2) {
    if (pos1 == pos2) return;

    node prev1 = NULL, prev2 = NULL, curr1 = head, curr2 = head;

    // Find the nodes at pos1 and pos2
    for (int i = 1; i < pos1 && curr1 != NULL; ++i) {
        prev1 = curr1;
        curr1 = curr1->next;
    }
    for (int i = 1; i < pos2 && curr2 != NULL; ++i) {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    if (curr1 == NULL || curr2 == NULL) return;

    // Swap nodes
    if (prev1 != NULL) prev1->next = curr2;
    else head = curr2;

    if (prev2 != NULL) prev2->next = curr1;
    else head = curr1;

    node temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
}

// 4. Remove the N-th node from the end of the list
void removeNthFromEnd(node& head, int n) {
    int len = size(head);
    if (n > len) return;

    node temp = head;
    if (n == len) {
        head = head->next;  // Remove head
        delete temp;
        return;
    }

    for (int i = 1; i < len - n; ++i) {
        temp = temp->next;
    }

    node toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

// 5. Separate odd and even nodes in a linked list
void separateOddAndEvenNodes(node head) {
    node oddHead = NULL, evenHead = NULL, oddTail = NULL, evenTail = NULL;

    while (head != NULL) {
        if (head->data % 2 == 0) {  // Even
            if (evenHead == NULL) {
                evenHead = evenTail = makeNode(head->data);
            }
            else {
                evenTail->next = makeNode(head->data);
                evenTail = evenTail->next;
            }
        }
        else {  // Odd
            if (oddHead == NULL) {
                oddHead = oddTail = makeNode(head->data);
            }
            else {
                oddTail->next = makeNode(head->data);
                oddTail = oddTail->next;
            }
        }
        head = head->next;
    }

    cout << "Odd nodes: ";
    printList(oddHead);
    cout << "Even nodes: ";
    printList(evenHead);
}

// 6. Divide linked list into k parts
void divideListIntoParts(node head, int k) {
    int totalSize = size(head);
    int partSize = totalSize / k, extraNodes = totalSize % k;

    for (int i = 0; i < k; ++i) {
        node partHead = NULL, partTail = NULL;
        int currentSize = partSize + (extraNodes > 0 ? 1 : 0);
        if (extraNodes > 0) --extraNodes;

        for (int j = 0; j < currentSize; ++j) {
            if (partHead == NULL) {
                partHead = partTail = makeNode(head->data);
            }
            else {
                partTail->next = makeNode(head->data);
                partTail = partTail->next;
            }
            head = head->next;
        }

        cout << "Part " << i + 1 << ": ";
        printList(partHead);
    }
}

// 7. Remove zero-sum consecutive nodes
node removeZeroSumConsecutiveNodes(node head) {
    node dummy = makeNode(0);  // Dummy node to handle edge cases
    dummy->next = head;
    node current = dummy;

    while (current != NULL) {
        node temp = current->next;
        int sum = 0;

        while (temp != NULL) {
            sum += temp->data;
            if (sum == 0) {
                current->next = temp->next;  // Remove nodes from current to temp
                break;
            }
            temp = temp->next;
        }

        current = current->next;
    }

    return dummy->next;
}

// 8. Automatically input values for the list
node autoInputList() {
    int numEntries = 39 + rand() % 21;  // Random number from 39 to 59
    node head = NULL, tail = NULL;

    for (int i = 0; i < numEntries; ++i) {
        int val = -99 + rand() % 199;  // Random value from -99 to 99
        node newNode = makeNode(val);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head;
}



// Main function with a menu
int main() {
    node head = NULL;  // Initialize an empty list
    int choice;

    do {
        cout << "Menu:\n";
        cout << "1. Add two numbers into linked list at specified positions\n";
        cout << "2. Copy list without random pointers\n";
        cout << "3. Swap two nodes in the list at specified positions\n";
        cout << "4. Remove the N-th node from the end of the list\n";
        cout << "5. Separate odd and even nodes in the list\n";
        cout << "6. Divide linked list into k parts\n";
        cout << "7. Remove zero-sum consecutive nodes from the list\n";
        cout << "8. Automatic input for the linked list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Add two numbers
            int pos1, pos2, val1, val2;
            cout << "Enter position 1: ";
            cin >> pos1;
            cout << "Enter value 1: ";
            cin >> val1;
            cout << "Enter position 2: ";
            cin >> pos2;
            cout << "Enter value 2: ";
            cin >> val2;

            addTwoNumbers(head, pos1, pos2, val1, val2);
            cout << "List after adding two numbers: ";
            printList(head);
        }
        else if (choice == 2) {
     // Copy list
     node copiedList = copyList(head);
     cout << "Copied list: ";
     printList(copiedList);
        }
 else if (choice == 3) {
     // Swap nodes
     int pos1, pos2;
     cout << "Enter position 1: ";
     cin >> pos1;
     cout << "Enter position 2: ";
     cin >> pos2;

     swapNodes(head, pos1, pos2);
     cout << "List after swapping nodes: ";
     printList(head);
        }
 else if (choice == 4) {
     // Remove the N-th node from the end
     int n;
     cout << "Enter N (position from the end): ";
     cin >> n;
     removeNthFromEnd(head, n);
     cout << "List after removing N-th node from end: ";
     printList(head);
        }
 else if (choice == 5) {
     // Separate odd and even nodes
     separateOddAndEvenNodes(head);
        }
 else if (choice == 6) {
     // Divide linked list into k parts
     int k;
     cout << "Enter number of parts (k): ";
     cin >> k;
     divideListIntoParts(head, k);
        }
 else if (choice == 7) {
     // Remove zero-sum consecutive nodes
     head = removeZeroSumConsecutiveNodes(head);
     cout << "List after removing zero-sum consecutive nodes: ";
     printList(head);
        }
 else if (choice == 8) {
     // Automatic input for the linked list
     head = autoInputList();
     cout << "List after automatic input: ";
     printList(head);
        }

    } while (choice != 0);

    return 0;
}
