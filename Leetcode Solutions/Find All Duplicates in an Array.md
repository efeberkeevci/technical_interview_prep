# 442. Find All Duplicates in an Array

Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    set = new Set();
    let duplicates = [];
    for(let i = 0; i<nums.length; i++){
        if(set.has(nums[i])){
            duplicates.push(nums[i]);
            set.delete(nums[i]);
        }
        else{
            set.add(nums[i]);
        }
    }
    return duplicates;
};
```