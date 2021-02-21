# 141. Linked List Cycle

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)
```
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
```

## Visited node checks solution
### 1) Traverse through the linked list and add the visited nodes to a list of visited nodes
### 2) If the current node is in the visited nodes list return true
### 3) If we reacht the end of the linked list without encountering a visited node, we return false

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    let visited_nodes = [];
    let current_node = head;
    while(current_node!= null && !visited_nodes.includes(current_node)){
        visited_nodes.push(current_node);
        current_node = current_node.next;
    }
    return current_node==null ?false : true;
};
```

# Fast pointer & Slow pointer approach

```javascript
var hasCycle = function(head) {
    if(head == null) return false;
    if(head.next == null) return false;
    let slow_pointer = head;
    let fast_pointer = head.next;
    
    while(fast_pointer!= null){
        if(fast_pointer == slow_pointer) return true;
        else{
            slow_pointer = slow_pointer.next;
            try{
                fast_pointer = fast_pointer.next.next;
            }
            catch{
                return false;
            }
        }
    }
    return false;
};

```
