# 844. Backspace String Compare

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.


```javascript
/**
 * @param {string} S
 * @param {string} T
 * @return {boolean}
 */
var backspaceCompare = function(S, T) {
    let s_index = 0;
    let t_index = 0;
    
    while(s_index<S.length ){
        if(S.charAt(s_index) == "#" && S.length != 0){
            if(S.charAt(0) != "#"){
                S = S.slice(0,s_index-1) + S.slice(s_index+1, S.length);
                s_index -= 2;
            }
            else{
                S = S.slice(0,s_index) + S.slice(s_index+1, S.length);
                s_index--;
            }
        }
        s_index++;
    }
    while(t_index<T.length){
        if(T.charAt(t_index) == "#" && T.length!= 0){
            if(T.charAt(0) != "#"){
                T = T.slice(0,t_index-1) + T.slice(t_index+1, T.length);
                t_index -= 2;
            }
            else{
                T = T.slice(0,t_index) + T.slice(t_index+1, T.length);
                t_index--;
            }    
        }
        t_index++;
    }
    return S==T;
};
```