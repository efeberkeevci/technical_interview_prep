# 111. Minimum Depth of Binary Tree

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var minDepth = function(root) {
    if(root == null) return 0;
    if(root != null && root.left == null && root.right == null) return 1;
    let left_cost = minDepth(root.left);
    let right_cost = minDepth(root.right);
    if(left_cost == 0 ) left_cost = Infinity;
    if(right_cost == 0) right_cost = Infinity;
    //console.log("Current node: ", root.val, " Left Cost: ", left_cost, " Right cost: ", right_cost);
    return Math.min(left_cost,right_cost)+1;
};
```