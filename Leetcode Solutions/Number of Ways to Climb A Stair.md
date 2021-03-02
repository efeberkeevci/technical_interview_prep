## You are climbing a staircase. It takes n steps to reach the top.
## Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
```
Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints: 1 <= n <= 45
```

### Sample problem instances and expected resulsts

```
case n = 1 count = 1

1 step

case n = 2 count = 2

1 step + 1 step
2 steps

case n = 3 count = 3

1 +1 +1
1+2
2+1

case n=4  count = 5

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2

case n=5  count = 8
1+1+1+1+1
1+1+1+2
1+1+2+1
1+2+1+1
2+1+1+1
2+2+1
2+1+2
1+2+2
```

```javascript
function count_possible_routes(n){
	if(n <= 2 )return n;
	return count_possible_routes(n-1) + count_possible_route(n-2);
}
```

Time complexity => O(2^n)
* This can be improved by utilizing a cache of already_computed smaller problems
* Every time we want to know the answer of count_possible_routes(i) where 0<= i <=n
* We look up to the cache if the length of the cache is bigger than i and 
  if so we retrive the result of count_possible_routes(i) by cache[i];
* If the corresponding result is not computed yet, we compute it and then store it in the cache.
* This decreases the time complexity to O(n), which is a significant improvement.



