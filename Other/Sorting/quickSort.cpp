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
- Base Case: Array size 1, return the element
- Recursive Step:
    - Pick a pivot from the array
    - Move the elements smaller than pivot to an array called lesser
    - Move the elements larger than pivot to an array called greater
    - Call quicksort with lesser and greater subarrays
    - updated lesser and greater with their sorted version upon return from the calls
    - return lesser + pivot + greater
*/
vector<int> quickSort(vector<int> arr){
    if(arr.size() <= 1) return arr;
    vector<int> lesser;
    vector<int> greater;
    int pivot = arr.size()/2;
    for(int i = 0; i<arr.size(); i++){
        if(i != pivot){
            if(arr[i] < arr[pivot]) lesser.push_back(arr[i]);
            else greater.push_back(arr[i]);
        }
    }
    lesser = quickSort(lesser);
    greater = quickSort(greater);
    lesser.push_back(arr[pivot]);
    lesser.insert(lesser.end(), greater.begin(), greater.end());
    return lesser;
}

int main(){
    int tmp[] = {4,5,1,9,8,7};
    vector<int> arr( tmp, tmp+6 );
    print_vector(arr);
    arr = quickSort(arr);
    print_vector(arr);
    return 0;
}