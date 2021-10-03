#include <stdlib.h>
#include <iostream>

using namespace std;
void print_arr(int arr[], int size){
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

void shift_and_insert(int arr[], int new_index, int end_index, int val){
    for(int i = end_index; i>new_index; i--){
        arr[i] = arr[i-1];
    }
    arr[new_index] = val;
    return;
}

/*
Sorting Algorithm: 
Starting from index 1, find an index where current element is less than the index+1 element
Insert the current element there and shift the array to the right by one
Keep doing this until reaching the end
*/

void insertionSort(int * arr, int size){
    for(int i = 1; i<size; i++){
        int new_index = i;
        while(new_index > 0 && arr[new_index-1] > arr[i]){new_index--;}
        shift_and_insert(arr,new_index,i,arr[i]);
    }
    return;
}

int main(){
    int tmp[] = {4,5,1,9,8,7};
    print_arr(tmp,6);
    insertionSort(tmp, 6);
    print_arr(tmp,6);
    return 0;
}