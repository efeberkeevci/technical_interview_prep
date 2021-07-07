#include <iostream>
#include <cmath>

using namespace std;
  /*
    Get upper and lower bound at of base
    
    while(base>0.001+x || base<x-0.001){
      if base bigger than make it smaller by taking the middle point of upper and lower bound
    }
  
  */

  /*
  1) Upper bound = n
      Lower bound = 1;
  2) while we havent reached the bound
      if base to the power n is larger than than the new base becomes the mid point between low bound and base
      else base becomes the mid point between upper bound and base
  
  */

/*
upper_bound 7   4    2.5  2.5
lower_bound 1             1.75
base        4   2.5  1.75

*/

double root(double x, unsigned int n) 
{
 double upper_bound = x;
 double lower_bound = 1;
 double base = (upper_bound+lower_bound)/2;
 while(pow(base,n)>0.001+x || pow(base,n)<x-0.001){
    if(pow(base,n)>0.001+x){
      upper_bound = base;
      base = (base+lower_bound)/2;
    }
   
   else{
     lower_bound = base;
     base = (upper_bound+base)/2;
   }
 }
  return base;
  
}

int main() {
  cout<<root(7,3)<<endl;
  return 0;
}