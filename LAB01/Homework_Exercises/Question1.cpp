//STT: 22521099
//Full name: Le Hoang Thien Phu
//Session 01 - Homework 01
#include <iostream>
#include <string>
#include <vector>  // For storing display outputs
using namespace std;

struct Song {
    string name;
    Song* next;
    Song* prev;
};

Song* createSong(const string& name) {
    Song* newSong = new Song();
    newSong->name = name;
    newSong->next = newSong->prev = NULL;
    return newSong;
}

bool isEmpty(Song* current) {
    return current == NULL;
}

void addSong(Song*& head, Song*& tail, const string& name) {
    Song* newSong = createSong(name);
    if (isEmpty(head)) {
        head = tail = newSong;
        head->next = head->prev = head;  // Circular link to itself
    }
    else {
        tail->next = newSong;
        newSong->prev = tail;
        newSong->next = head;
        head->prev = newSong;
        tail = newSong;
    }
}

void playNext(Song*& current) {
    if (!isEmpty(current)) {
        current = current->next;
    }
}

void playPrev(Song*& current) {
    if (!isEmpty(current)) {
        current = current->prev;
    }
}

void removeSong(Song*& head, Song*& tail, Song*& current, const string& name) {
    if (isEmpty(head)) return;

    Song* temp = head;
    do {
        if (temp->name == name) {
            if (temp == head && temp == tail) {
                head = tail = current = NULL;  // Only one song in the playlist
            }
            else {
                if (temp == head) head = head->next;
                if (temp == tail) tail = tail->prev;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp == current) current = temp->next;
            }
            delete temp;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

// Display the current playlist from tail to head
void displayPlaylist(Song* tail, vector<string>& output) {
    if (isEmpty(tail)) {
        output.push_back("Playlist is empty");
        return;
    }

    Song* temp = tail;
    string result;
    do {
        result += temp->name + " ";
        temp = temp->prev;
    } while (temp != tail);

    result.pop_back(); // Remove the trailing space
    output.push_back(result);
}

int main() {
    
    cout << "STT: 22521099\n";
    cout << "Full name: Le Hoang Thien Phu\n";
    cout << "Session 01 - Homework 01\n";
    cout << endl;
    
    Song* head = NULL;
    Song* tail = NULL;
    Song* current = NULL;

    vector<string> output;  // Buffer for display outputs
    int n;
    cin >> n;
    cin.ignore();  // To ignore newline after reading n
    string command, songName;

    for (int i = 0; i < n; ++i) {
        getline(cin, command);

        if (command.find("ADD") == 0) {
            songName = command.substr(4);  // Extract song name after "ADD "
            addSong(head, tail, songName);
            if (current == NULL) current = head;  // Start playing the first song
        }
        else if (command == "NEXT") {
            playNext(current);
        }
        else if (command == "PREV") {
            playPrev(current);
        }
        else if (command.find("REMOVE") == 0) {
            songName = command.substr(7);  // Extract song name after "REMOVE "
            removeSong(head, tail, current, songName);
        }
        else if (command == "DISPLAY") {
            displayPlaylist(tail, output);  // Display from tail to head to reverse order
        }
    }

    // Output all results at once
    for (const string& line : output) {
        cout << line << endl;
    }

    return 0;
}
