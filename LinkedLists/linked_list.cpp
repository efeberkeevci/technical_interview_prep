#include<iostream>  
  
using namespace std; 

class Node{
    public:
        int data;
        Node * next;
    Node(){
        next = NULL;
    }
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
            //TODO: What to do when index is bigger than the size
            Node * current_node = head;
            for(int i = 0; i < index; i++ ){
                current_node = current_node->next;
            }
            return current_node->data;
        }

        //adds an item to the front of the list
        void push_front(int value){
            Node * new_node = new Node();
            new_node->next = head;
            new_node->data = value;
            head = new_node;

            return;
        }

        //remove front item and return its value
        int pop_front(){
            int front_node_data = head->data;
            head = head->next;
            return front_node_data;
        }

        //adds an item at the end
        void push_back(int value){
            Node * current_node = head;
            while(current_node->next != NULL){
                current_node = current_node->next;
            }
            Node * new_node = new Node();
            new_node->next = NULL;
            new_node->data = value;
            current_node->next = new_node;
            return;
        }

        //removes end item and returns its value
        int pop_back(){
            Node * current_node = head;
            while(current_node->next->next != NULL){
                current_node = current_node->next;
            }
            int back_node_data = current_node->next->data;
            current_node->next = NULL;
            return back_node_data;
        }   

        //get value of front item
        int front(){
            return head->data;
        }

        //get value of end item
        int back(){
            Node * current_node = head;
            while(current_node->next != NULL){
                current_node = current_node->next;
            }
            return current_node->data;
        }

        //insert value at index, so current item at that index is pointed to by new item at index
        void insert(int index, int value){
            Node * current_node = head;
            for(int i = 0; i<index-1; i++){
                current_node = current_node->next;
            }
            Node * new_node = new Node();
            new_node->data = value;
            new_node->next = current_node->next;
            current_node->next = new_node;
            return;
        }

        //removes node at given index
        void erase(int index){
            //TODO: what to do if it is the last element
            Node * current_node = head;
            for(int i = 0; i<index-1; i++){
                current_node = current_node->next;
            }
            if(current_node->next != NULL){
                current_node->next = current_node->next->next;
            }
            return;
        }

        //returns the value of the node at nth position from the end of the list
        int value_n_from_end(int n){
            return value_at(size()-n-1);
        }

        //reverses the list
        void reverse(){
            //TODO handle the no node case, one node case, two nodes case
            Node * prev_node = NULL;
            Node * current_node = head;
            Node * next_node = head->next;

            while(next_node!= NULL){
                current_node->next = prev_node;
                prev_node = current_node;
                current_node = next_node;
                next_node = next_node->next;
            }
            current_node->next = prev_node;
            head = current_node;
            return;
        }
        //removes the first item in the list with this value
        void remove_value(int value){
            Node * current_node = head;
            int index = 0;
            while(current_node != NULL){
                if(current_node->data == value){
                    erase(index);
                    return;
                }else{
                    current_node = current_node->next;
                    index++;
                }
            }
            return;
        }

};
void print_linked_list(LinkedList list){
    Node * current_node = list.head;
    cout<<"Printing current linked list: ";
    while(current_node != NULL){
        cout<<current_node->data<< " ";
        current_node = current_node->next;
    }
    cout<<endl;
};

int main(){
    LinkedList list;
    cout<<"Linked List tests"<<endl;
    cout<<"Size of the list "<<list.size()<<endl;
    cout<<"Is list empty "<<list.empty()<<endl;

    cout<<endl;
    cout<<"Pushing 1,15,9 to the front in order"<<endl;
    list.push_front(1);
    list.push_front(15);
    list.push_front(9);
    print_linked_list(list);

    cout<<"Value at index 1: "<<list.value_at(1)<<endl;
    cout<<"Value at index 2: "<<list.value_at(2)<<endl;
    cout<<"Value at front: "<<list.front()<<endl;
    cout<<"Value at back: "<<list.back()<<endl;

    cout<<"Popping front"<<endl;
    list.pop_front();
    print_linked_list(list);
    
    cout<<"Pushing 15 to the front 3 times back to back"<<endl;
    list.push_front(15);
    list.push_front(15);
    list.push_front(15);
    print_linked_list(list);


    cout<<"Popping back"<<endl;
    list.pop_back();
    print_linked_list(list);


    cout<<"Pushing 74 to the back"<<endl;
    list.push_back(74);

    cout<<"Pushing 3 to the front"<<endl;
    list.push_front(3);
    print_linked_list(list);

    cout<<"Removing first element with value 15"<<endl;
    list.remove_value(15);
    print_linked_list(list);

    cout<<"Removing element at index 4"<<endl;
    list.erase(4);
    print_linked_list(list);

    cout<<"Inserting 87 at index 2"<<endl;
    list.insert(2,87);
    print_linked_list(list);


    cout<<"Value at index 0 from end: "<<list.value_n_from_end(0)<<endl;
    cout<<"Value at index 1 from end: "<<list.value_n_from_end(1)<<endl;
    cout<<"Value at index 2 from end: "<<list.value_n_from_end(2)<<endl;

    cout<<"Reverse the linked list"<<endl;
    list.reverse();
    print_linked_list(list);

    return 1;
}