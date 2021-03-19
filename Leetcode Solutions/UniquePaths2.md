# 63. Unique Paths II
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

```javascript
/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid,memo={}) {
    let m;
    let n;
    try{
        m = obstacleGrid.length;
        n = obstacleGrid[0].length;
    }
    catch{
        return 0;
    }
    let key = m + "." +n;
    if(key in memo) return memo[key];
    if(obstacleGrid[0][0]==1) return 0;
    if(m == 0 || n == 0) return 0;
    if(m == 1 && n == 1) return 1;
    let downGrid = Create2DArray(m-1,n);
    let rightGrid = Create2DArray(m,n-1);
    for(let i = 0; i<m-1; i++){
        for(let j = 0; j<n; j++){
            downGrid[i][j] = obstacleGrid[i+1][j];
        }
    }
    for(let i = 0; i<m; i++){
        for(let j = 0; j<n-1; j++){
            rightGrid[i][j] = obstacleGrid[i][j+1];
        }
    }
    let computed_val = uniquePathsWithObstacles(downGrid,memo) + uniquePathsWithObstacles(rightGrid,memo);
    memo[key] = computed_val;
    return computed_val;
};

function Create2DArray(rows,columns) {
   var x = new Array(rows);
   for (var i = 0; i < rows; i++) {
       x[i] = new Array(columns);
   }
   return x;
}


```