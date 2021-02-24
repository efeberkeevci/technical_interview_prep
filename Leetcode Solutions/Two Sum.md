# 1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
```

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */


/*
Hash Table Solution => Improved lookup due to hash table usage
Approach => Loop through the elements of the nums array...
...If the complement(target-cur_element) exists return true
Time Complexity = O(n)
Space Complexity = O(n)
*/

function twoSum(nums,target){
    let map = new Map();
    for(let i = 0; i<nums.length; i++){
        map.set(nums[i],i);
    }
    
    for(let i = 0; i<nums.length; i++){
        let complement = target - nums[i];
        if(map.has(complement) && (map.get(complement) != i)){
            return [i,map.get(complement)];
        }
    }
}


/*
Brute Force Solution
Time Complexity = O(n^2)
Space Complexity = O(1)
*/


var twoSum = function(nums, target) {
    for(let i = 0; i<nums.length-1; i++){
        for(let j = i+1; j<nums.length; j++){
            if(nums[i]+nums[j] == target){
                return [i,j];
            }
        }
    }
};

```