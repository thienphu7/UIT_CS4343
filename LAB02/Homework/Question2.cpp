//STT: 22521099
//Full Name: Le Hoang Thien Phu
//Homework - Exercise 02
//Notes or Remarks: ......
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// BrowserHistory class definition
class BrowserHistory {
private:
    stack<string> backStack;   // Stack to store visited URLs
    stack<string> forwardStack; // Stack to store forward URLs
    string currentUrl;         // Holds the current URL

public:
    // Constructor to initialize the starting page
    BrowserHistory(string homepage) {
        currentUrl = homepage;
        cout << "Current web: " << currentUrl << endl;
    }

    // Visit a new URL, clearing forward history
    void visit(string url) {
        backStack.push(currentUrl); // Save current page to back stack
        currentUrl = url;           // Update the current page
        while (!forwardStack.empty()) { // Clear forward stack
            forwardStack.pop();
        }
        cout << "Current web: " << currentUrl << endl;
    }

    // Go back to the previous URL
    void back() {
        if (!backStack.empty()) {
            forwardStack.push(currentUrl); // Save current page to forward stack
            currentUrl = backStack.top();  // Move back to the previous page
            backStack.pop();
        }
        else {
            cout << "No pages to go back to." << endl;
        }
        cout << "Current web: " << currentUrl << endl;
    }

    // Go forward to the next URL
    void forward() {
        if (!forwardStack.empty()) {
            backStack.push(currentUrl);    // Save current page to back stack
            currentUrl = forwardStack.top(); // Move forward to the next page
            forwardStack.pop();
        }
        else {
            cout << "No pages to go forward to." << endl;
        }
        cout << "Current web: " << currentUrl << endl;
    }

    // Function to display the current page
    string getCurrentPage() {
        return currentUrl;
    }
};

int main() {
    // Create a browser history starting from a homepage
    cout << "* In default *" << endl;
    BrowserHistory browser("ThienPhuDepTrai.com");
    cout << endl;
    cout << "* Input *" << endl;
    cout << "browser.visit('httt.uit.edu.vn')" << endl;
    cout << "browser.visit('uit.edu.vn')" << endl;
    cout << "browser.back()" << endl;
    cout << "browser.forward()" << endl;
    cout << "browser.visit('daa.uit.edu.vn')" << endl;
    cout << "browser.forward()" << endl;
    cout << endl;
    cout << "* Output *" << endl;
    // Visiting new pages
    browser.visit("httt.uit.edu.vn");  // Outputs "Current web: httt.uit.edu.vn"
    browser.visit("uit.edu.vn");       // Outputs "Current web: uit.edu.vn"

    // Going back and forward through history
    browser.back();  // Outputs "Current web: httt.uit.edu.vn"
    browser.forward(); // Outputs "Current web: uit.edu.vn"

    // Visiting a new page clears forward history
    browser.visit("daa.uit.edu.vn"); // Outputs "Current web: daa.uit.edu.vn"

    browser.back();  // Outputs "Current web: uit.edu.vn"
    return 0;
}
