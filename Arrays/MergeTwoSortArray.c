#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int * mergeArrays(const int *myArray, size_t myLength,
                  const int *alicesArray, size_t alicesLength)
{
    // combine the sorted arrays into one large sorted array
    
    /*
    Example:
    int myArray[6] =     {3, 4, 6, 10, 11, 15};
    int alicesArray[6] = {1, 5, 8, 12, 14, 19};
    */
  
    int* merged_array = (int *) malloc((myLength + alicesLength)*sizeof(int));
    
    unsigned int count1 = 0;
    unsigned int count2 = 0;

    
    
    while(count1<=myLength-1 || count2<=alicesLength-1 ){
        printf("count1: %d, count2: %d\n", count1, count2);
        if(count1+1 <= myLength && count2+1 <= alicesLength){
            
          if(myArray[count1]<=alicesArray[count2]) {
            *(merged_array +count1+count2) = myArray[count1];
            count1++;
          }
          else{
            *(merged_array +count1+count2) = alicesArray[count2];
            count2++;
          }
        }
        else if(count1 == myLength){
           *(merged_array +count1+count2) = alicesArray[count2];
           count2++;
        }
            else{
                *(merged_array +count1+count2) = myArray[count1];
                count1++;
            }
    }

    return merged_array;
}


int main(){
    const int myArray[] = {2, 4, 6};
    const int alicesArray[] = {1, 3, 7};
    int *actual = mergeArrays(myArray, 3, alicesArray, 3);
    for(int i = 0; i<6; i++){
      printf("%d ", actual[i]); 
    }
    


  return 0;
}























































//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>


  
/*
5
5 50 50 70 80 100
7 100 95 90 80 70 60 50
3 70 90 80
3 70 90 81
9 100 99 98 97 96 95 94 93 91
*/

/*

float above_average(char str[]){
  //Read the first char/s and save it to a variable called number_of_students
  
  //Create a for loop to iterate through each student to get the sum
  char * token = strtok(str, " ");
  int sum = 0;
  int number_of_students = atoi(token);
  int student_scores[number_of_students];
  int count = 0;
  
  while(token != NULL){
    student_scores[count] = atoi(token);
    sum += atoi(token);
    token = strtok(NULL, " ");
  }
  
  int num_of_students_above_average = 0;
  float average = sum/number_of_students;
  for(int i = 0; i<number_of_students; i++){
    if(student_scores[i]> average) num_of_students_above_average++;
  }
  
  return 100 * num_of_students_above_average/(float)number_of_students ;    
  
  
}

int main() {
  char input[] = "5 50 50 70 80 100\0";
  
  printf("Percentage of students above average: %0.3f%\n ", above_average(input));
  return 0;
}


*/