# 377. Combination Sum IV
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The answer is guaranteed to fit in a 32-bit integer.

```
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
```
## My Approach: Dynamic Programming with memoization.
```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var combinationSum4 = function(nums, target,memo={}) {
    if(target in memo) return memo[target];
    if(target == 0) return 1;
    if(target<0) return 0;
    let sum_of_ways = 0;
    for(let i = 0; i<nums.length; i++){
        sum_of_ways += combinationSum4(nums,target-nums[i],memo);
    }
    memo[target] = sum_of_ways;
    return sum_of_ways;
};
```