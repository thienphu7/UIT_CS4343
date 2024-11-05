- [TABLE OF CONTENTS](#table-of-contents)
- [1. Exercises In-Class](#1-exercises-in-class)
  - [1.1. Part 1](#11-part-1)
  - [1.2. Part 2](#12-part-2)
- [2. Homework](#2-homework)
  - [2.1. Question 1: Tower of Hanoi](#21-question-1-tower-of-hanoi)
    - [2.1.1. Problem Statement](#211-problem-statement)
  - [2.2. Question 2: Browser History Management](#22-question-2-browser-history-management)
    - [2.2.1. Problem Statement](#221-problem-statement)
    - [2.2.2. Test case](#222-test-case)
  - [2.3. Question 3](#23-question-3)
    - [2.3.1. Problem Statement](#231-problem-statement)
    - [2.3.2. Test case](#232-test-case)
      - [2.3.2.1. Test case 1](#2321-test-case-1)
      - [2.3.2.2. Test case 2](#2322-test-case-2)


# 1. Exercises In-Class
## 1.1. Part 1
Write a program to implement a stack using a singly linked list *(or an array)* to temporarily store integers *(or characters)*. Perform the following requirements:
1. Write a function to **initialize** the stack.
2. Write a function to **check if the stack is empty**. If empty, return true, otherwise return false.
3. Write a function to **check if the stack is full** *(if applicable)*. If full, return true, otherwise return false.
4. Write a function to **push** an element onto the stack.
5. Write a function to **pop** an element from the stack.
6. Print the **TOP** element of the stack.

In the main function, write a **menu** to display the above choices.
## 1.2. Part 2
Write a program to implement a queue using a singly linked list *(or an array)* to temporarily store integers *(or characters)*. Perform the following requirements:
1. Write a function to **initialize** the queue.
2. Write a function to **check if the queue is empty**. If empty, return true, otherwise return false.
3. Write a function to **check if the queue is full** *(if applicable)*. If full, return true, otherwise return false.
4. Write a function to **enqueue** an element into the queue.
5. Write a function to **dequeue** an element from the queue.
6. Print the **REAR** and **FRONT** elements of the queue.

In the main function, write a **menu** to display the above choices.

# 2. Homework
## 2.1. Question 1: Tower of Hanoi
### 2.1.1. Problem Statement
In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of different sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order of size from top to bottom (i.e., each disk sits on top of an even larger one).

**Constraints:**

Illustration:

• https://upload.wikimedia.org/wikipedia/commons/4/4f/Tower_of_Hanoi.gif

• https://upload.wikimedia.org/wikipedia/commons/6/60/Tower_of_Hanoi_4.gif

## 2.2. Question 2: Browser History Management
### 2.2.1. Problem Statement
Simulate a browser’s back and forward navigation using a stack. Implement the following functionalities:

• visit(url): Visit a new URL.

• back(): Go back to the previous URL.

• forward(): Go forward to the next URL.

### 2.2.2. Test case
browser.visit("httt.uit.edu.vn")

browser.visit("uit.edu.vn")

browser.back() // returns "httt.uit.edu.vn"

browser.forward() // returns "uit.edu.vn

browser.visit("daa.uit.edu.vn")

browser.back() // returns "uit.edu.vn"

## 2.3. Question 3
### 2.3.1. Problem Statement 
The problem involves a queue of n people, each with a distinct height, arranged from left to right. Given an array called heights, where heights[i] represents the height of the i-th person, the task is to determine how many people each person can see to their right. A person can see another if everyone in between is shorter than both of them. Specifically, the i-th person can see the j-th person if i < j and all heights between them are less than both heights[i] and heights[j]. The solution should return an array answer, where answer[i] indicates the number of people visible to the i-th person on their right.

### 2.3.2. Test case
#### 2.3.2.1. Test case 1
**Input:** heights = [10,6,8,5,11,9]

**Output:** [3,1,2,1,0]

**Explanation**

Person 0 can see person 1, 2, and 4.

Person 1 can see person 2.

Person 2 can see person 3 and 4.

Person 3 can see person 4.

Person 4 can see person 5.

Person 5 can see no one since nobody is to the right of them.

#### 2.3.2.2. Test case 2
**Input:** heights = [5,1,2,3,10]

**Output:** [4,1,1,1,0]

**Constraints**

• n = heights.length

• 1 ≤ n ≤ 105

• 1 ≤ heights[i] ≤ 105

• All values of heights are unique.
