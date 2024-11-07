//STT: 22521099
//Full name: Le Hoang Thien Phu
//Session 01 - Homework 02
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BrowserHistory {
    vector<string> history;
    int currentIndex;

public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currentIndex = 0;
    }

    void visit(string url) {
        history.resize(currentIndex + 1);  // Remove forward history
        history.push_back(url);
        currentIndex++;
    }

    string back(int steps) {
        currentIndex = max(0, currentIndex - steps);
        return history[currentIndex];
    }

    string forward(int steps) {
        currentIndex = min((int)history.size() - 1, currentIndex + steps);
        return history[currentIndex];
    }
};

int main() {
    vector<string> output;

    // Input: list of commands and associated data
    string commandsInput, dataInput;
    getline(cin, commandsInput);  // e.g., ["BrowserHistory", "visit", "visit", "back", ...]
    getline(cin, dataInput);  // e.g., [["uit.edu.vn"], ["google.com"], [1], ...]

    // Process commands
    vector<string> commands;
    commandsInput = commandsInput.substr(1, commandsInput.size() - 2);  // Remove brackets []
    size_t pos = 0;
    while ((pos = commandsInput.find(", ")) != string::npos) {
        commands.push_back(commandsInput.substr(1, commandsInput.substr(0, pos).size() - 2));  // Remove quotes
        commandsInput.erase(0, pos + 2);
    }
    commands.push_back(commandsInput.substr(1, commandsInput.size() - 2));

    // Process data input
    vector<vector<string>> data;
    dataInput = dataInput.substr(1, dataInput.size() - 2);  // Remove outer []
    while ((pos = dataInput.find("], [")) != string::npos) {
        string temp = dataInput.substr(0, pos);
        vector<string> innerData;
        size_t innerPos = 0;
        temp = temp.substr(1, temp.size() - 2);  // Remove brackets []
        while ((innerPos = temp.find(", ")) != string::npos) {
            innerData.push_back(temp.substr(1, innerPos - 2));  // Remove quotes
            temp.erase(0, innerPos + 2);
        }
        if (temp[0] == '"') innerData.push_back(temp.substr(1, temp.size() - 2));  // Handle strings
        else innerData.push_back(temp);  // Handle numbers
        data.push_back(innerData);
        dataInput.erase(0, pos + 4);
    }
    // Process last element
    dataInput = dataInput.substr(1, dataInput.size() - 2);
    vector<string> lastData;
    size_t lastPos = 0;
    while ((lastPos = dataInput.find(", ")) != string::npos) {
        lastData.push_back(dataInput.substr(1, lastPos - 2));
        dataInput.erase(0, lastPos + 2);
    }
    if (dataInput[0] == '"') lastData.push_back(dataInput.substr(1, dataInput.size() - 2));
    else lastData.push_back(dataInput);
    data.push_back(lastData);

    // Initialize BrowserHistory
    BrowserHistory* browserHistory = new BrowserHistory(data[0][0]);
    output.push_back("null");

    // Execute commands
    for (int i = 1; i < commands.size(); i++) {
        if (commands[i] == "visit") {
            browserHistory->visit(data[i][0]);
            output.push_back("null");
        }
        else if (commands[i] == "back") {
            string result = browserHistory->back(stoi(data[i][0]));
            output.push_back("\"" + result + "\"");
        }
        else if (commands[i] == "forward") {
            string result = browserHistory->forward(stoi(data[i][0]));
            output.push_back("\"" + result + "\"");
        }
    }

    // Print output
    cout << "[";
    for (int i = 0; i < output.size(); i++) {
        cout << "\"" << output[i] << "\"";
        if (i != output.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
