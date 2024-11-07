#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Create a new node
Node* makeNode(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}

// To print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Find the number of elements in linked list
int size(Node* a) {
    int cnt = 0;
    while (a != NULL) {
        cnt++;
        a = a->next;
    }
    return cnt;
}

// 1. Find the Middle Node of a Linked List
void FindMiddle(Node*& a) {
    if (a == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    int len = size(a);
    Node* temp = a;

    // Traverse the list up to the middle
    for (int i = 0; i < len / 2 - 1; i++) {
        temp = temp->next;
    }

    // For even-length lists, print the two middle elements
    if (len % 2 == 0) {
        cout << temp->data << " " << temp->next->data << endl;
    }
    // For odd-length lists, print the single middle element
    else {
        temp = temp->next;
        cout << temp->data << endl;
    }
}

// 2. Detect a Cycle in a Linked List
bool detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// 3. Combine Two Sorted Linked Lists
Node* mergeSortedLists(Node* l1, Node* l2) {
    Node* dummy = makeNode(0);
    Node* tail = dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1 != NULL) ? l1 : l2;
    Node* mergedList = dummy->next;
    delete dummy;
    return mergedList;
}

// 4. Find the Intersection of Two Linked Lists
Node* getIntersectionNode(Node* head1, Node* head2) {
    if (!head1 || !head2) return NULL;

    Node* start1 = head1;
    while (start1) {
        Node* start2 = head2;
        while (start2) {
            Node* temp1 = start1;
            Node* temp2 = start2;

            // Check if a contiguous subsequence starting at start1 matches a subsequence starting at start2
            while (temp1 && temp2 && temp1->data == temp2->data) {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }

            // If temp2 has reached the end, then we have found a match
            if (temp2 == NULL) {
                Node* intersection = makeNode(start1->data);
                Node* tail = intersection;
                temp1 = start1->next;

                while (temp1 && start2) {
                    if (temp1->data == start2->data) {
                        tail->next = makeNode(temp1->data);
                        tail = tail->next;
                        temp1 = temp1->next;
                        start2 = start2->next;
                    }
                    else {
                        break;
                    }
                }

                return intersection;
            }

            start2 = start2->next;
        }
        start1 = start1->next;
    }
    return NULL;
}
// 5. Reverse a Linked List
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// 6. Eliminate Duplicates from a Sorted Linked List
Node* removeDuplicates(Node* head) {
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            Node* nextNext = current->next->next;
            delete current->next;
            current->next = nextNext;
        }
        else {
            current = current->next;
        }
    }
    return head;
}

// 7. Check if a Linked List is a Palindrome
bool isPalindrome(Node* head) {
    if (head == NULL) return true;

    Node* slow = head;
    Node* fast = head;
    Node* prev_of_slow = NULL;
    Node* mid = NULL;
    Node* second_half = NULL;

    if (head != NULL && head->next != NULL) {
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev_of_slow = slow;
            slow = slow->next;
        }

        if (fast != NULL) {
            mid = slow;
            slow = slow->next;
        }

        second_half = reverseList(slow);
        prev_of_slow->next = NULL;

        while (head != NULL && second_half != NULL) {
            if (head->data != second_half->data) return false;
            head = head->next;
            second_half = second_half->next;
        }

        return true;
    }
    return true;
}

// 8. Search for Nodes with Value X
Node* searchValue(Node* head, int x) {
    Node* result = NULL;
    Node* tail = NULL;
    int index = 0;

    while (head != NULL) {
        if (head->data == x) {
            Node* newNode = makeNode(index);
            if (result == NULL) {
                result = newNode;
                tail = result;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        head = head->next;
        index++;
    }
    return result;
}

// MENU
void menu() {
    cout << endl;
    cout << "Personal Information:\n";
    cout << "STT: 22521099\n";
    cout << "Full name: Le Hoang Thien Phu\n";
    cout << "In-class Exercise - Part 1\n";
    cout << "Notes or Remarks:......\n";
    cout << endl;

    cout << "----------------------MENU-----------------------------" << endl;
    cout << "1. Find the Middle Node of a Linked List" << endl;
    cout << "2. Detect a Cycle in a Linked List" << endl;
    cout << "3. Combine Two Sorted Linked Lists" << endl;
    cout << "4. Find the Intersection of Two Linked Lists" << endl;
    cout << "5. Reverse a Linked List" << endl;
    cout << "6. Eliminate Duplicates from a Sorted Linked List" << endl;
    cout << "7. Check if a Linked List is a Palindrome" << endl;
    cout << "8. Search for Nodes with Value X" << endl;
    cout << "9. Exit" << endl;
    cout << "------------------------------------------------------" << endl;
}

//Input linked list from keyboard
void InputList(Node*& head) {
    int value;
    Node* tail = NULL;

    cout << "Enter numbers for the list (enter -1 to finish):" << endl;
    while (true) {
        cin >> value;
        if (value == -1) break;

        Node* newNode = makeNode(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

// To clean up
void deleteList(Node*& head) {
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = NULL;
}

// Main Function
int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    Node* result = NULL;
    int choice;
    int x;

    while (1) {
        menu();
        cin >> choice;

        if (choice == 1) {
            deleteList(list1);  // Reset list1 before new population
            list1 = NULL;
            InputList(list1);
            FindMiddle(list1);
        }
            
        else if (choice == 2) {
            deleteList(list1);  // Reset list1 before new population
            list1 = NULL;
            InputList(list1);
            cout << (detectCycle(list1) ? "Cycle detected" : "No cycle") << endl;
        }
            
        else if (choice == 3) {
            cout << "Input list1:" << endl;
            InputList(list1);
            cout << "Input list2:" << endl;
            InputList(list2);
            result = mergeSortedLists(list1, list2);
            printList(result);
            deleteList(result); // Clean up the memory
        }
            
        else if (choice == 4) {
            Node* head1 = NULL;
            Node* head2 = NULL;
            Node* intersectionPoint = NULL;

            cout << "Input list1:" << endl;
            InputList(head1);

            cout << "Input list2:" << endl;
            InputList(head2);

            intersectionPoint = getIntersectionNode(head1, head2);

            if (intersectionPoint == NULL)
                cout << "No Intersection Point" << endl;
            else
                cout << "Intersection Point: " << intersectionPoint->data << endl;

            // Clean up
            deleteList(head1);
            deleteList(head2);
        }
            
        else if (choice == 5) {
            cout << "Input list1:" << endl;
            InputList(list1);
            result = reverseList(list1);
            printList(result);
            deleteList(result); // Clean up the memory
        }
            
        else if (choice == 6) {
            cout << "Input list1:" << endl;
            InputList(list1);
            result = removeDuplicates(list1);
            printList(result);
        }
            
        else if (choice == 7) {
            cout << "Input list1:" << endl;
            InputList(list1);
            cout << (isPalindrome(list1) ? "Palindrome" : "Not Palindrome") << endl;
        }
        
        else if (choice == 8) {
            cout << "Input list1:" << endl;
            InputList(list1);
            cout << "Enter value to search: ";
            cin >> x;
            result = searchValue(list1, x);
            if (result) {
                printList(result);
                deleteList(result); // Clean up the memory
            }
            else {
                cout << "Value not found" << endl;
            }
        }
            
        else if (choice == 9) {
            break;
        }
        else {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    deleteList(list1);
    deleteList(list2);
    
    return 0;
}
