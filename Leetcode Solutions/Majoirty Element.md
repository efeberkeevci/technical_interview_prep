# 169. Majority Element

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.


```javascript

/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    
    if(nums.length == 1) return nums[0];
    
    let left_pointer = 0;
    let right_pointer = nums.length-1;
    map = new Map();
    
    
    while(right_pointer - left_pointer>=0){
        
        if(map.has(nums[left_pointer])){
            let current_count =  map.get(nums[left_pointer]);
            map.set(nums[left_pointer],current_count+1);
        }else{
            map.set(nums[left_pointer],1);
        }
        if(map.get(nums[left_pointer])> nums.length/2) return nums[left_pointer];
        
        
        
        if(map.has(nums[right_pointer])){
            let current_count =  map.get(nums[right_pointer]);

            map.set(nums[right_pointer], current_count+1);
        }else{
            map.set(nums[right_pointer],1);
        }
        if(map.get(nums[right_pointer])> nums.length/2) return nums[right_pointer];

        left_pointer++;
        right_pointer--;
    }

};
```