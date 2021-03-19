# 62. Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

## I used dynamic programming with memoization approach to solve the problem
* Base case => If I have 1x1 matrix, I have 1 path only
* If we have one of the dimensions 0, there are 0 paths
* Since we can only move right or down, we compute the unique paths for m-1xn path and mxn-1 path recursively
* Then we add the subpaths and return

```javascript
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n, memo ={}) {
    let key = m + "." +n;
    if(key in memo) return memo[key];
    if(m == 0 || n == 0) return 0;
    if(m == 1 && n == 1) return 1;
    let computed_val = uniquePaths(m-1,n,memo) + uniquePaths(m,n-1,memo);
    memo[key] = computed_val;
    return computed_val;
};
```