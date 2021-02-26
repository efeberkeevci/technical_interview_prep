# 977. Squares of a Sorted Array
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Approach used : Two pointers
```javascript
/*
    Algorithm :
    Create two indeces, one starting at the beginning of the array, the other starting from the end
    add the square of the bigger element to the array
    
    do this until two indeces are the same
    and add the square of the smallest square before returning the array  
    */

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function(nums) {
    
    let left_index = 0;
    let right_index = nums.length-1;
    ret_arr_index = right_index;
    
    let ret_arr = new Array(nums.length);
    
    while(left_index != right_index ){
        if(Math.abs(nums[left_index]) > Math.abs(nums[right_index]) ){
            ret_arr[ret_arr_index] = nums[left_index] * nums[left_index];
            left_index++;
        }
        else{
            ret_arr[ret_arr_index] = nums[right_index] * nums[right_index];
            right_index--;
        }
        ret_arr_index--;
    }
    ret_arr[ret_arr_index] = nums[right_index] * nums[right_index];
    return ret_arr;
};

```