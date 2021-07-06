
# H-Tree Construction

An H-tree is a geometric shape that consists of a repeating pattern resembles the letter “H”.

It can be constructed by starting with a line segment of arbitrary length, drawing two segments of the same length at right angles to the first through its endpoints, and continuing in the same vein, reducing (dividing) the length of the line segments drawn at each stage by √2.

Here are some examples of H-trees at different levels of depth:


Write a function drawHTree that constructs an H-tree, given its center (x and y coordinates), a starting length, and depth. Assume that the starting line is parallel to the X-axis.

Use the function drawLine provided to implement your algorithm. In a production code, a drawLine function would render a real line between two points. However, this is not a real production environment, so to make things easier, implement drawLine such that it simply prints its arguments (the print format is left to your discretion).

Analyze the time and space complexity of your algorithm. In your analysis, assume that drawLine's time and space complexities are constant, i.e. O(1).

```cpp


#include <iostream>
/*
 Algortihm:

   Base condition depth == 1
   
   Call drawH with x and y
   Then compute 4 endpoints for each end of H
   for each of these endpoints call drawTree with depth-1
   Call drawH and return

*/

void drawLine (double x0, double y0, double x1, double y1){
  
};

void drawHTree (double x, double y, double len, double depth) {
  if(depth == 1) {
    drawH(x,y,len);
    return;
  }
  drawHTree(x-len/2,y+len/2,len/sqrt(2),depth-1);
  drawHTree(x-len/2,y-len/2,len/sqrt(2),depth-1);
  drawHTree(x+len/2,y-len/2,len/sqrt(2),depth-1);
  drawHTree(x+len/2,y+len/2,len/sqrt(2),depth-1);
  
  drawH(x,y,len);
  return;
}

void drawH(double x, double y, double len){
  drawLine(x-len/2,y,x+len/2,y);
  drawLine(x-len/2,y+len/2,x-len/2,y-len/2);
  drawLine(x+len/2,y+len/2,x+len/2,y-len/2);
  return;
}

int main()
{
    std::cout << "Practice makes Perfect!" << std::endl;
    return 0;
}
```