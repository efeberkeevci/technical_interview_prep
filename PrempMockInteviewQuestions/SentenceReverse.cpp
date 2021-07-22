#include <iostream>
#include <vector>

using namespace std;

/*
  arr = [ 'p', 'e', 'r', 'f', 'e', 'c', 't', '  ',
                'm', 'a', 'k', 'e', 's', '  ',
                'p', 'r', 'a', 'c', 't', 'i', 'c', 'e' ]
          
  (0,7), (8,13), (14,21)

*/
/*
  ALGORITHM:
    Reverse the entire array
    Starting from index 0, look for whitespace character which signals a word
    reverse the character of that word
    repeat this until the end of the array
  
  */

void reverseWord(vector<char>* arr, int begin, int end){
  cout<<begin<<" "<<end<<endl;
  for(int i = 0; i<(begin+end)/2 -begin; i++){
    char temp = (*arr)[i+begin];
    (*arr)[i+begin] = (*arr)[end-i-1];
    (*arr)[end-i-1] = temp;

  }
 
  return;
}
vector<char> reverseWords(vector<char>& arr ) 
{
  for(int i = 0; i< arr.size()/2; i++){
    char temp = arr[i];
    arr[i] = arr[arr.size()-i-1];
    arr[arr.size()-i-1] = temp;
  }  
  for(int i = 0; i<22; i++){
      cout<<arr[i];
  }
  int i = 0;
  int word_begin = 0;

  while(i < arr.size()){
    if(arr[i] -' ' == 0){
       reverseWord(&arr, word_begin, i);
       word_begin = i+1;
    }
    i++;
  }
  reverseWord(&arr, word_begin, arr.size());
  return arr;
}


int main() {
  char arr2[] = {'p', 'e', 'r', 'f', 'e', 'c', 't', ' ','m', 'a', 'k', 'e', 's', ' ','p', 'r', 'a', 'c', 't', 'i', 'c', 'e'};
  vector<char> arr;
  for(int i = 0; i<22; i++){
      arr.push_back(arr2[i]);
  }
  vector<char> arr3 = reverseWords(arr);
  
  for(int i = 0; i<22; i++){
      cout<<arr3[i];
  }
  
  return 0;
}