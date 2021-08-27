# 322. Coin Change
* You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
* Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
* You may assume that you have an infinite number of each kind of coin.

 
```
Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0

Example 4:

Input: coins = [1], amount = 1
Output: 1

Example 5:

Input: coins = [1], amount = 2
Output: 2

```
## My Approach: Dynamic Programming with Memoization

```javascript
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function(coins, amount, memo= {}) {
    if(amount in memo) return memo[amount];
    if(amount<0) return -1;
    if(amount == 0) return 0;
    else{
        let min_route_cost = Infinity;
        let are_any_non_negative_route_cost = false;
        for(let i = 0; i<coins.length; i++){
            let route_cost = coinChange(coins, amount-coins[i],memo);
            if(route_cost >= 0 ) {
                are_any_non_negative_route_cost = true;
                if(min_route_cost>route_cost) min_route_cost = route_cost;
            }
        }
        if(are_any_non_negative_route_cost) {
            memo[amount] = min_route_cost+1;
            return min_route_cost+1;
        }
        else {
            memo[amount] = -1;
            return -1
        };
    }
};
```