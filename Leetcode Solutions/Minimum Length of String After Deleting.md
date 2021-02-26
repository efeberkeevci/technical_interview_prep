# 1750. Minimum Length of String After Deleting Similar Ends

Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:

    Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
    Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
    The prefix and the suffix should not intersect at any index.
    The characters from the prefix and suffix must be the same.
    Delete both the prefix and the suffix.

Return the minimum length of s after performing the above operation any number of times (possibly zero times).

Optimized solution
```javascript 
var minimumLength = function(s) {
    let left_index = 0;
    let right_index = s.length - 1;
    let left_index_end;
    let right_index_end;

    while ((s.charAt(left_index) == s.charAt(right_index)) && left_index != right_index && s.length != 0) {
        left_index = 0;
        left_index_end = left_index + 1;
        right_index_end = right_index - 1;

        //detect max substring of the repeating character in suffix and/or prefix
        while (s.charAt(left_index) == s.charAt(left_index_end)) {
            left_index_end++;
        }
        while (s.charAt(right_index) == s.charAt(right_index_end)) {
            right_index_end--;
        }

        //remove them from the char array
        s = s.slice(left_index_end, right_index_end + 1);
        right_index = s.length - 1;

    }
    return s.length;
};
```

Initial solution
```javascript 
/**
 * @param {string} s
 * @return {number}
 */


var minimumLength = function(s) {
    //empty string check => returns 0
    
    s = s.split("");
    let left_index = 0;
    let right_index = s.length-1;
    let left_index_end;
    let right_index_end;

    while(s[left_index] == s[right_index] && left_index != right_index && s.length != 0){
        left_index = 0;
        left_index_end = left_index+1;
        right_index_end = right_index-1;
        //detect max substring of the repeating character in suffix and/or prefix
        while(s[left_index] == s[left_index_end]){
            left_index_end++;
        }
        while(s[right_index] == s[right_index_end]){
            right_index_end--;
        }
        
        //remove them from the char array

        
        s.splice(right_index_end, right_index-right_index_end);
        s.splice(left_index,left_index_end-left_index);
        right_index = s.length-1;

        }
    return s.length;
};

```