## Write a program to find the node at which the intersection of two singly linked lists begins.

```
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8

Input Explanation: 
The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). 
From the head of A, it reads as [4,1,8,4,5]. 
From the head of B, it reads as [5,6,1,8,4,5]. 
There are 2 nodes before the intersected node in A; 
There are 3 nodes before the intersected node in B.
```


```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    let upper_pointer = headA;
    let lower_pointer = headB;
    let visited_nodes_list = [];
    
    while(upper_pointer != null || lower_pointer !=null ){
        
        if(upper_pointer != null){
            if(visited_nodes_list.includes(upper_pointer)){
            return upper_pointer;
            }
            else{
                visited_nodes_list.push(upper_pointer);
            }
            upper_pointer = upper_pointer.next;
        }
        
        if(lower_pointer != null){
            if(visited_nodes_list.includes(lower_pointer)){
            return lower_pointer;
            }
            else{
                visited_nodes_list.push(lower_pointer);
            }
            lower_pointer = lower_pointer.next;
        }
    }
};

```