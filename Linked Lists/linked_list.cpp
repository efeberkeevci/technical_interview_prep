#include<iostream>  
  
using namespace std; 
class Node{
    public:
        int data;
        Node * next;
};


class LinkedList{
    public:
        Node * head;

        LinkedList(){
            head = NULL;
        }

        LinkedList(Node * node){
            head = node;
        }

        //returns number of data elements in list
        int size(){
            Node * current_node = head;
            int size = 0;
            while(current_node != NULL){
                current_node = current_node->next;
                size++;
            }
            return size;
        }

        //bool returns true if empty
        bool empty(){
            return size() == 0 ? true : false;
        }

        //returns the value of the nth item (starting at 0 for first)
        int value_at(int index){

        }

        //- adds an item to the front of the list
        void push_front(int value){

        }

        //remove front item and return its value
        int pop_front(){

        }

        //- adds an item at the end
        void push_back(int value){

        }

        //removes end item and returns its value
        int pop_back(){

        }

        //get value of front item
        int front(){

        }

        //get value of end item
        int back(){

        }

        //insert value at index, so current item at that index is pointed to by new item at index
        void insert(int index, int value){

        }

        //removes node at given index
        void erase(int index){

        }

        //- returns the value of the node at nth position from the end of the list
        int value_n_from_end(int n){}

        //reverses the list
        void reverse(){

        }
        //- removes the first item in the list with this value
        void remove_value(int value){

        }

};

int main(){
    return 1;
}