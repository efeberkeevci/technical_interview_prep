# 287. Find the Duplicate Number
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */


//BruteForce 
//Time => O(nlogn) due to sorting
//Space => O(n) due to sorting if merge sort
var findDuplicate = function(nums) {
    nums.sort();
    for(let i = 0; i<nums.length-1; i++){
        if(nums[i] == nums[i+1]) return nums[i];
    }
};

//Set usage
//Time => O(n)
//Space => O(n)
function findDuplicate(nums){
    set = new Set();
    for(let i = 0; i< nums.length; i++){
        if(set.has(nums[i])) return nums[i];
        else set.set(nums[i],1);
    }
}
```