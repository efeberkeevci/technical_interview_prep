#include<iostream>  
#include<algorithm> 
#include <math.h>
  
using namespace std; 

/*
int find_largest_element(int [] arr){
    //Pick the last element of the array
    //Move the smaller ones to the left of the pivot
    //Move the larger ones to the right of the pivot


    //If the right array is equal to length of zero than return
    //If not, do the same thing by calling find_largest_element on right array
    
}
*/
int findLargest(int array[],int begin,int end){
    if(begin == end) {
        return array[begin];
    }
    else{
        int mid = floor((end-begin) / 2) + begin;

        int largestLeft = findLargest(array, begin, mid);

        int largestRight = findLargest(array, mid + 1, end);

        return max(largestLeft, largestRight);
    }
}

    
int main(){
    int arr[9] = {9,6,2,4,1,7,3,5,8};
    cout<<findLargest(arr,0,9)<<endl;
    return 1;
}