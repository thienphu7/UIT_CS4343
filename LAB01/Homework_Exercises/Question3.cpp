//STT: 22521099
//Full name: Le Hoang Thien Phu
//Session 01 - Homework 03
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class AuthenticationManager {
    int timeToLive;
    unordered_map<string, int> tokens;  // tokenId -> thời gian hết hạn

public:
    AuthenticationManager(int ttl) : timeToLive(ttl) {}

    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + timeToLive;
    }

    void renew(string tokenId, int currentTime) {
        if (tokens.find(tokenId) != tokens.end() && tokens[tokenId] > currentTime) {
            tokens[tokenId] = currentTime + timeToLive;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (auto it = tokens.begin(); it != tokens.end();) {
            if (it->second <= currentTime) {
                it = tokens.erase(it);  // Xóa token đã hết hạn
            }
            else {
                ++count;
                ++it;
            }
        }
        return count;
    }
};

int main() {
    vector<string> output;

    // Nhập input đúng định dạng yêu cầu
    string commandsInput, dataInput;
    getline(cin, commandsInput);  // Nhập dòng đầu tiên ["AuthenticationManager", "renew", "generate", ...]
    getline(cin, dataInput);  // Nhập dòng thứ hai [[5], ["aaa", 1], ...]

    // Tách các lệnh từ commandsInput
    vector<string> commands;
    commandsInput = commandsInput.substr(1, commandsInput.size() - 2);  // Bỏ dấu []
    size_t pos = 0;
    while ((pos = commandsInput.find(", ")) != string::npos) {
        commands.push_back(commandsInput.substr(0, pos).substr(1, commandsInput.substr(0, pos).size() - 2));  // Bỏ dấu ""
        commandsInput.erase(0, pos + 2);
    }
    commands.push_back(commandsInput.substr(1, commandsInput.size() - 2));  // Thêm lệnh cuối cùng

    // Tách các dữ liệu từ dataInput
    vector<vector<string>> data;
    dataInput = dataInput.substr(1, dataInput.size() - 2);  // Bỏ dấu []
    while ((pos = dataInput.find("], [")) != string::npos) {
        string temp = dataInput.substr(0, pos);
        vector<string> innerData;
        size_t innerPos = 0;
        temp = temp.substr(1, temp.size() - 2);  // Bỏ dấu []
        while ((innerPos = temp.find(", ")) != string::npos) {
            innerData.push_back(temp.substr(1, innerPos - 2));  // Bỏ dấu ""
            temp.erase(0, innerPos + 2);
        }
        if (temp[0] == '"') innerData.push_back(temp.substr(1, temp.size() - 2));  // Chuỗi
        else innerData.push_back(temp);  // Số
        data.push_back(innerData);
        dataInput.erase(0, pos + 4);
    }
    // Xử lý phần tử cuối cùng
    dataInput = dataInput.substr(1, dataInput.size() - 2);  // Bỏ dấu []
    vector<string> lastData;
    size_t lastPos = 0;
    while ((lastPos = dataInput.find(", ")) != string::npos) {
        lastData.push_back(dataInput.substr(1, lastPos - 2));  // Bỏ dấu ""
        dataInput.erase(0, lastPos + 2);
    }
    if (dataInput[0] == '"') lastData.push_back(dataInput.substr(1, dataInput.size() - 2));  // Chuỗi
    else lastData.push_back(dataInput);  // Số
    data.push_back(lastData);

    // Khởi tạo AuthenticationManager với thời gian sống
    AuthenticationManager* manager = new AuthenticationManager(stoi(data[0][0]));
    output.push_back("null");

    // Duyệt qua từng lệnh và xử lý
    for (int i = 1; i < commands.size(); i++) {
        if (commands[i] == "generate") {
            manager->generate(data[i][0], stoi(data[i][1]));
            output.push_back("null");
        }
        else if (commands[i] == "renew") {
            manager->renew(data[i][0], stoi(data[i][1]));
            output.push_back("null");
        }
        else if (commands[i] == "countUnexpiredTokens") {
            int currentTime = stoi(data[i][0]);
            output.push_back(to_string(manager->countUnexpiredTokens(currentTime)));
        }
    }

    // Xuất kết quả
    cout << "[";
    for (int i = 0; i < output.size(); i++) {
        cout << "\"" << output[i] << "\"";
        if (i != output.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
