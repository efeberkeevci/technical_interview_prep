# 41. First Missing Positive
Given an unsorted integer array nums, find the smallest missing positive integer.

```
 

Example 1:

Input: nums = [1,2,0]
Output: 3

Example 2:

Input: nums = [3,4,-1,1]
Output: 2

Example 3:

Input: nums = [7,8,9,11,12]
Output: 1


```
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    let min=1;
    let max=1;
    
    for(let i = 0; i<nums.length;i++){
        if(nums[i]>0){
            if(min>nums[i]) min = nums[i];
            if(max<nums[i]) max = nums[i];
        }else{
            nums.splice(i,1);
            i--;
        }
        
    }
    for(let i= min; i<=max; i++){
        if(!nums.includes(i)) return i;
    }
    return max+1;
};
```