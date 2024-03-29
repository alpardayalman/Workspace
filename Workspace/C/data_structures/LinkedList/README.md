# Linked Lists

## Assignments

```
Given a linked list, write a function to reverse every alternate k nodes (where k is an input 
to the function) in an efficient way. Give the complexity of your algorithm.

Example:

Inputs:   1->2->3->4->5->6->7->8->9->NULL and k = 3
Output:   3->2->1->4->5->6->9->8->7->NULL. 
```
```
Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node 
from the end of the linked list.

Input:

LinkedList: 1->2->3->4->5->6->7->8->9     N = 2
Output: 8

Explanation: In the first example, there are 9 nodes in linked list and we need to find 2nd node 
from end. 2nd node from end os 8.  
```
```
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the 
function) in the linked list. If the number of nodes is not a multiple of k then left-out nodes, 
in the end, should be considered as a group and must be reversed (See Example 2 for clarification).

Input:
LinkedList: 1->2->2->4->5->6->7->8      K = 4
Output: 4 2 2 1 8 7 6 5 

Explanation: 
The first 4 elements 1,2,2,4 are reversed first and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.

Input:
LinkedList: 1->2->3->4->5       K = 3
Output: 3 2 1 5 4 

Explanation: 
The first 3 elements are 1,2,3 are reversed first and then elements 4,5 are reversed.Hence, 
the resultant linked list is 3->2->1->5->4.
```
---
