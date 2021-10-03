#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
void print_vector(vector<int> arr){
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
/*
Sorting Algorithm: 
- Base Case: if single element left(begin == end)
- Recursive Step: 
    - Divide the current array portion to left and right subarrays until single elements left
    - Then merge left and right subarrays with this method
        - make two pointers to the beginning of left and right subaraary
        - push the smaller one to the ret_array and increment that pointer
        - if the pointer reaches the end then just keep pushing the values that the other pointer points to and keep incrementing that pointer
        - do this until both pointer reaches the end of their subarrays
    - Return the formed array
*/
vector<int> mergeSort(vector<int> arr, int begin, int end){
    vector<int> ret_arr;
    if(begin>end) return ret_arr;
    if(begin == end){
        ret_arr.push_back(arr[begin]);
        return ret_arr;
    }
    int mid = (begin+end)/2;
    vector<int> left_subarr = mergeSort(arr, begin, mid);
    vector<int> right_subarr = mergeSort(arr, mid+1,end);

   
    int left_index = 0; 
    int right_index = 0;
    
    while(left_index < left_subarr.size() || right_index < right_subarr.size()){
        if(right_index == right_subarr.size()){
            ret_arr.push_back(left_subarr[left_index]);
            left_index++;
            continue;
        }
        if(left_index == left_subarr.size()){
            ret_arr.push_back(right_subarr[right_index]);
            right_index++;
            continue;
        }
        if(right_index == right_subarr.size() || left_subarr[left_index] < right_subarr[right_index]){
            ret_arr.push_back(left_subarr[left_index]);
            left_index++;
        }else{
            ret_arr.push_back(right_subarr[right_index]);
            right_index++;
        }
    }
    
    return ret_arr;

}



int main(){
    int tmp[] = {4,5,1,9,8,7};
    vector<int> arr( tmp, tmp+6 );
    print_vector(arr);
    arr = mergeSort(arr,0,arr.size()-1);
    print_vector(arr);
    return 0;
}