91. Decode Ways
Medium

A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"

To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

    "AAJF" with the grouping (1 1 10 6)
    "KJF" with the grouping (11 10 6)

Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.

 
Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).


## My approach: Dynamic programming with memoization
```javascript
/**
 * @param {string} s
 * @return {number}
 */
const encodings = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15","16", "17", "18", "19", "20", "21", "22","23", "24", "25", "26"];
var numDecodings = function(s,memo={}) {
    if(s in memo) return memo[s];
    if(s == "") return 1;
    let sum_of_ways = 0;
    for(let i = 0; i<encodings.length;i++){
        if(s.startsWith(encodings[i]) && s.length>=encodings[i].length){
            let new_substring = s.substring(encodings[i].length);
            let ways = numDecodings(new_substring,memo);
            sum_of_ways += ways
        }
    }
    memo[s]= sum_of_ways;
    return sum_of_ways;
};
```