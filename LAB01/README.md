- [1. In-Class Exercises](#1-in-class-exercises)
  - [1.1. Part 1](#11-part-1)
  - [1.2. Part 2](#12-part-2)
- [2. Homework](#2-homework)
  - [2.1. Question 1: Music player](#21-question-1-music-player)
    - [2.1.1. Problem statement](#211-problem-statement)
    - [2.1.2. Test case](#212-test-case)
  - [2.2. Question 2: Web Browser back and next](#22-question-2-web-browser-back-and-next)
  - [2.3. Question 3: AuthenticationManager Class](#23-question-3-authenticationmanager-class)

# 1. In-Class Exercises
## 1.1. Part 1
|Question  | Status |
|:---|:---:|
|1. Find the Middle Node of a Linked List |Easy|
|2. Detect a Cycle in a Linked List |Easy|
|3. Combine Two Sorted Linked Lists |Easy|
|4. Find the Intersection of Two Linked Lists |Easy|
|5. Reverse a Linked List| Easy|
|6. Eliminate Duplicates from a Sorted Linked List| Easy|
|7. Check if a Linked List is a Palindrome |Easy|
|8. Write a function to search for nodes with the value X in the list. If found, return the addresses of the nodes; if not found, return NULL.| Easy|
## 1.2. Part 2
|Question  | Status |
|:---|:---:|
|1. Add Two Numbers| Medium|
|2. Copy List with Random Pointers| Medium|
|3. Swap Nodes in a Linked List |Medium|
|4. Remove the N-th Node from the End of a List| Medium|
|5. Separate Odd and Even Nodes in a Linked List |Medium|
|6. Divide a Linked List into Parts|Medium|
|7. Remove Zero-Sum Consecutive Nodes from a Linked List| Medium|
|8. Write a function to input values for a list using the automatic input method, with values selected from the range [-99; 99]. The number of entries is randomly chosen from the range [39; 59] (using a function to insert at the end of the list)| Medium|
# 2. Homework 
## 2.1. Question 1: Music player
### 2.1.1. Problem statement
You are tasked with designing a simple music player using a linked list. The player should be able to perform the following operations:
1. Add a Song: Add a song to the end of the playlist.
2. Play Next: Move to the next song in the playlist. If at the end, loop back to the first song.
3. Play Previous: Move to the previous song in the playlist. If at the beginning, loop to the last song.
4. Remove a Song: Remove a song by its name from the playlist.
5. Display Playlist: Output the current playlist in order.

***Input:***

• The first line contains an integer n, the number of operations.

• The next n lines contain operations in the format:

- ADD <song name> to add a song.
- NEXT to play the next song.
- PREV to play the previous song.
- REMOVE <song name> to remove a song.
- DISPLAY to display the current playlist.

***Output:***

For each DISPLAY operation, output the current playlist as a space-separated list of song names.

**Constraints**

• 1 ≤ n ≤ $10^5$

• Song names are unique and consist of lowercase English letters.

### 2.1.2. Test case

***Input:***

6
ADD song1

ADD song2

NEXT

DISPLAY

REMOVE song1

DISPLAY

***Output:***

song2 song1

song2


>1. How would you handle edge cases, such as trying to remove a song that doesn’t exist?
>2. How can you efficiently loop back to the start or end of the list?
>3. What data structure(s) would you use to implement this playlist, and why?
>4. How would you ensure that operations like NEXT and PREV are efficient, given the constraints?
## 2.2. Question 2: Web Browser back and next
In a web browser that operates with a single tab, the user starts on the homepage and can navigate to various URLs, retrace their steps in the browsing history, or advance through it. To implement this functionality, the ‘BrowserHistory‘ class will be designed with the following specifications:

• **Initialization:** The constructor ‘BrowserHistory(string homepage)‘ initializes the instance with the designated homepage URL.

• **Visiting URLs:** The method ‘void visit(string url)‘ allows the user to navigate to a new URL from the current page, while simultaneously clearing any forward history.

• **Navigating Back:** The method ‘string back(int steps)‘ enables the user to move backward through the history by a specified number of steps. If the number of steps exceeds the available history, the user will return only as far back as possible. This method returns the current URL after the backward movement.

• **Navigating Forward:** The method ‘string forward(int steps)‘ allows the user to advance through the history by a specified number of steps. Similar to the back method, if the number of steps exceeds the available forward history, the user will only move forward as far as possible. The current URL is returned after this operation.

**Example Usage**

Consider the following sequence of operations:

***Input:***

["BrowserHistory", "visit", "visit", "visit", "back", "back", "forward", "visit", "forward", "back", "back"] [["uit.edu.vn"], ["google.com"], ["facebook.com"], ["youtube.com"], [1], [1], [1], ["linkedin.com"], [2], [2], [7]\]

***Output:***

[null, null, null, null, "facebook.com", "google.com", "facebook.com", null, "linkedin.com", "google.com", "uit.edu.vn"]

**Explanation**
1. An instance of ‘BrowserHistory‘ is created with the homepage set to ”leetcode.com”.
2. The user visits ”google.com”, then ”facebook.com”, and subsequently ”youtube.com”.
3. The user navigates back once, returning to ”facebook.com”, and then again to ”google.com”.
4. The user moves forward one step to ”facebook.com”.
5. The user visits ”linkedin.com”, clearing the forward history.
6. The user attempts to move forward two steps but cannot, as there is no forward history.
7. The user navigates back two steps, returning to ”facebook.com” and then ”google.com”.
8. Finally, the user attempts to move back seven steps but can only return to ”leetcode.com”.

**Constraints**

• The length of the homepage string is between 1 and 20 characters.

• The length of any URL is also between 1 and 20 characters.

• The number of steps for navigation is limited to a maximum of 100.

• Both the homepage and URLs consist of lowercase English letters and periods.

• The total number of method calls to ‘visit‘, ‘back‘, and ‘forward‘ will not exceed 5000.

>An authentication system utilizes authentication tokens to manage user sessions. For each session, a unique authentication token is issued to the user, which is set to expire after a specified duration, known as timeToLive, measured in seconds from the current time. If the token is renewed, the expiration time is adjusted to extend timeToLive seconds from the new current time, which may differ from the previous one.

## 2.3. Question 3: AuthenticationManager Class
The AuthenticationManager class should be implemented with the following functionalities:

• **Constructor:** The constructor AuthenticationManager(int timeToLive) initializes the authentication manager with the defined timeToLive duration.

• **Token Generation:** The method generate(string tokenId, int currentTime) creates a new token associated with the specified tokenId at the given currentTime in seconds.

• **Token Renewal:** The method renew(string tokenId, int currentTime) allows for the renewal of an unexpired token identified by tokenId at the specified currentTime. If no unexpired token exists for the provided tokenId, the request is disregarded, resulting in no action taken.

• **Counting Unexpired Tokens:** The method countUnexpiredTokens(int currentTime) returns the total number of tokens that remain unexpired at the specified currentTime. It is crucial to note that if a token’s expiration occurs at time t, any subsequent actions, such as renewal or counting unexpired tokens, will consider the expiration to have taken place prior to those actions.

**Example Usage**

Consider the following sequence of operations:

***Input:***

["AuthenticationManager", "renew", "generate", "countUnexpiredTokens", "generate", "renew", "renew", "countUnexpiredTokens"]
[[5], ["aaa", 1], ["aaa", 2], [6], ["bbb", 7], ["aaa", 8], ["bbb", 10], [15]\]

***Output:***

[null, null, null, 1, null, null, null, 0]

**Explanation**
1. An instance of AuthenticationManager is created with a timeToLive of 5 seconds.
2. The renew method is called for tokenId "aaa" at time 1, but no token exists, so no action is taken.
3. A new token with tokenId "aaa" is generated at time 2.
4. At time 6, the countUnexpiredTokens method returns 1, as the token with tokenId "aaa" is still valid.
5. A new token with tokenId "bbb" is generated at time 7.
6. The renew method for tokenId "aaa" is called at time 8, but the token has expired at time 7, so the request is ignored.
7. The renew method for tokenId "bbb" is executed at time 10, successfully renewing the token, which will now expire at time 15.
8. Finally, at time 15, the countUnexpiredTokens method is invoked, which returns 0, as both tokens have expired.

**Constraints**

• The value of timeToLive must be between 1 and $10^8$.

• The currentTime must also fall within the range of 1 to $10^8$.

• The length of tokenId is restricted to a maximum of 5 characters, consisting solely of lowercase letters.

• Each call to generate will utilize unique tokenId values.

• The values of currentTime across all function calls will be strictly increasing.

• The total number of calls to all functions combined will not exceed 2000.