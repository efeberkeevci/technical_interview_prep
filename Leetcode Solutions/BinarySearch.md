# 704 Binary Search

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    return binarySearch(0,nums.length,nums,target);
};

function binarySearch(left,right,nums,target){
    if(left>=right){
        return -1;
    }
    let mid = Math.floor((left+right)/2);
    if(nums[mid] == target ){
        return mid;
    }
    else if(nums[mid] > target){
         return binarySearch(left,mid,nums,target);
    }
    else{
        return binarySearch(mid+1,right,nums,target);
    }
}
```