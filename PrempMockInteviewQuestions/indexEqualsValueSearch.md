
Array Index & Element Equality

Given a sorted array arr of distinct integers, write a function indexEqualsValueSearch that returns the lowest index i for which arr[i] == i. Return -1 if there is no such index. Analyze the time and space complexities of your solution and explain its correctness.

Examples:

input: arr = [-8,0,2,5]
output: 2 # since arr[2] == 2

input: arr = [-1,0,3,6]
output: -1 # since no index in arr satisfies arr[i] == i.
"

Approach:

1. Brute Force
* Go through each element. If the index equal to element at index return index, if not found at the end of loop return -1 
* O(n)

2. Binary Search
* Since the array is sorted we can use this in our advantate.
* If begin bigger than end return -1
* Compute the middle index
* If middle index is equal to element and middle index return middle index
* If element is bigger than index recurse on right subarray
* If element is smaller than index recurse on left subarray

```cpp
#include <iostream>
#include <vector>

using namespace std;


int helper(const vector<int> &arr, int begin, int end){
  if(begin > end) return -1;
  int middle = floor((begin+end)/2);
  if(arr[middle] == middle) return middle;
  if(arr[middle] < middle) return helper(arr,middle+1,end);
  return helper(arr,0,middle-1);
}
int indexEqualsValueSearch(const vector<int> &arr) 
{
  // your code goes here
  return helper(arr,0,arr.size()-1);
  
}
int main() {
  vector<int> arr;
  arr.push_back(-8);
  arr.push_back(0);
  arr.push_back(2);
  arr.push_back(5);

  arr.clear();
  arr.push_back(0);
  arr.push_back(6);
  arr.push_back(7);
  arr.push_back(8);
  arr.push_back(9);


  cout<<indexEqualsValueSearch(arr)<<endl;
  return 0;
}
```