# 20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.


```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(str) {
      let stack = [];
      let char_arr = str.split("");

      for(let i = 0; i<char_arr.length; i++){
          let current_char = char_arr[i];
          if(stack.length > 0){
            let top = stack.pop();
            if(current_char == ")" && top == "("){
              continue;
            }else if(current_char == "}" && top == "{"){
              continue;
            }else if(current_char == "]" && top == "["){
                continue;
              }else{
                stack.push(top);
                stack.push(current_char);
              }
          }
          else{
              stack.push(current_char);
          }
      }
      return stack.length == 0 ? true : false;
};

```