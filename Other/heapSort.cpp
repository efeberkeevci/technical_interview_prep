#include <stdlib.h>
#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
void print_vector(vector<int> arr){
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
/*
Sorting Algorithm: 
    Create a heap
    Push each element of the given array to the heap
    Pop from heap and insert to return array until heap is empty
*/
vector<int> heapSort(vector<int> arr){
   vector<int> ret_arr;
   auto greater = [](const int num1, const int num2){
       return num1>num2;
   };
   priority_queue<int, vector<int> , decltype(greater)> heap(greater);
   
   for(int i = 0 ; i<arr.size(); i++){
       heap.push(arr[i]);
   }
   while(!heap.empty()){
       ret_arr.push_back(heap.top());
       heap.pop();
   }
   return ret_arr;
   
}

int main(){
    int tmp[] = {4,5,1,9,8,7};
    vector<int> arr( tmp, tmp+6 );
    print_vector(arr);
    arr = heapSort(arr);
    print_vector(arr);
    return 0;
}