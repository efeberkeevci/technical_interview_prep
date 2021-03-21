# 112. Path Sum

Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
Constraints:

    The number of nodes in the tree is in the range [0, 5000].
    -1000 <= Node.val <= 1000
    -1000 <= targetSum <= 1000

### This is the question that I realized to look at constraints more closely. My initial answer was construvturd on only positive node values and positive targetSum. After an incorrect submission I realized that I also ened to consider my case and found this solution. 

## My Solution
* Base Cas => if the current node is a leaf
* If so, can we reach the targetSum? if yes return true, if so return false
* If it is not leaf, make two recursive calls to the left and right of the tree(with targetSum = targetSum-current_node.val) and return their ORd results.

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
 * @param {number} targetSum
 * @return {boolean}
 */
var hasPathSum = function(root, targetSum) {
    if (root == null) return false
    if(root.left == null && root.right == null){
        if (targetSum-root.val == 0) return true;
        else return false
    }
    else return hasPathSum(root.left, targetSum- root.val) || hasPathSum(root.right, targetSum - root.val)
            
};

```