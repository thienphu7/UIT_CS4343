1. Homework


1.1. Question 1: Tower of Hanoi
   
In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of different sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order of size from top to bottom (i.e., each disk sits on top of an even larger one).

Illustration:

• https://upload.wikimedia.org/wikipedia/commons/4/4f/Tower_of_Hanoi.gif

• https://upload.wikimedia.org/wikipedia/commons/6/60/Tower_of_Hanoi_4.gif

Constraints:

(1) Only one disk can be moved at a time.

(2) A disk is slid off the top of one tower onto another tower.

(3) A disk cannot be placed on top of a smaller disk. Write a program to move the disks from the first tower to the last using Stacks.


1.2. Question 2: Browser History Management
   
Problem Statement:

Simulate a browser’s back and forward navigation using a stack. Implement the following functionalities:

• visit(url): Visit a new URL.

• back(): Go back to the previous URL.

• forward(): Go forward to the next URL.

Example:

browser.visit("httt.uit.edu.vn")

browser.visit("uit.edu.vn")

browser.back() // returns "httt.uit.edu.vn"

browser.forward() // returns "uit.edu.vn

browser.visit("daa.uit.edu.vn")

browser.back() // returns "uit.edu.vn"


1.3. Question 3
   
The problem involves a queue of n people, each with a distinct height, arranged from left to right. Given an array called heights, where heights[i] represents the height of the i-th person, the task is to determine how many people each person can see to their right. A person can see another if everyone in between is shorter than both of them. Specifically, the i-th person can see the j-th person if i < j and all heights between them are less than both heights[i] and heights[j]. The solution should return an array answer, where answer[i] indicates the number of people visible to the i-th person on their right.

1.3.1. Example 1

Input: heights = [10,6,8,5,11,9]

Output: [3,1,2,1,0]

Explanation:

Person 0 can see person 1, 2, and 4.

Person 1 can see person 2.

Person 2 can see person 3 and 4.

Person 3 can see person 4.

Person 4 can see person 5.

Person 5 can see no one since nobody is to the right of them.

1.3.2. Example 2

Input: heights = [5,1,2,3,10]

Output: [4,1,1,1,0]

Constraints:

• n = heights.length

• 1 ≤ n ≤ 105

• 1 ≤ heights[i] ≤ 105

• All values of heights are unique
